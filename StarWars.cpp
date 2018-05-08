#include "StarWars.h"

const int REBEL_TEAM     = 0;
const int IMPERIAL_TEAM  = 1;

StarWars::StarWars() {

}

StarWars::~StarWars() {

    for (unsigned int i = 0; i < m_imperialShips.size();i++) {
        delete m_imperialShips[i];
        m_imperialShips[i] = NULL;
    }
    for (unsigned int i = 0; i < m_rebelShips.size();i++) {
        delete m_rebelShips[i];
        m_rebelShips[i] = NULL;
    }
}

bool StarWars::loadShips(char* files[]) {

    string impName,impType,impAttack,impDefence;
    int imperialAttack, imperialDefence;

    string rebName, rebType, rebAttack, rebDefence;
    int rebelAttack, rebelDefence;
    fstream inFile;

    // Loading Imperial Ships
    inFile.open(files[0]);
    if (inFile.is_open()) {
        while (getline(inFile,impName,',')) {
            getline(inFile,impType,',');
            getline(inFile,impAttack,',');
            getline(inFile,impDefence);
            imperialAttack  = atoi(impAttack.c_str());
            imperialDefence = atoi(impDefence.c_str());
            m_imperialShips.push_back(
                new Imperial(impName,impType,imperialAttack,imperialDefence));
        }
        inFile.close();
    } else {
        inFile.close();
        cout << "EMPTY" << endl;
        return 0;
    }
    // Loading Rebel Ships
    inFile.open(files[1]);
    if (inFile.is_open()) {
    while (getline(inFile,rebName,',')) {
        getline(inFile,rebType,',');
        getline(inFile,rebAttack,',');
        getline(inFile,rebDefence);
        rebelAttack  = atoi(rebAttack.c_str());
        rebelDefence = atoi(rebDefence.c_str());
        m_rebelShips.push_back(
            new Rebel(rebName,rebType,rebelAttack,rebelDefence));
        }
        // Closes the Rebel File
        inFile.close();
    } else {
        inFile.close();
        cout << "EMPTY" << endl;
        return 0;
    }
    return 1;
}

void StarWars::Start(char* files[]) {
    bool shipComp;
    cout << "Welcome to Star Wars." << endl;
    shipComp = loadShips(files);
    int shipNum = 0;
    if (shipComp) {
        cout << "Ships Loaded." << endl;
        do {
        cout << "How many ships would you like on your team? " << endl;
        cin >> shipNum;
        } while ((shipNum < 1) || (shipNum > 666));
    createTeams(shipNum);
    cout << "The battle begins..." << endl;
    battle();
    }
}

void StarWars::createTeams(int numShips) {
    srand(time(NULL));
    int imperialRand = rand() % m_imperialShips.size();
    int rebelRand    = rand() % m_rebelShips.size();

    // Player 1 - Rebels, Us
    // Player 2 - Imperial, Them

    // Creating the Rebel Team (Player 1)
    for (int i = 0; i < numShips;i++) {
        m_myShips.enqueue(m_rebelShips[rebelRand]);
        //cout << "Rebel: " << rebelRand << endl;
        rebelRand = rand() % m_rebelShips.size();
    }
    // Creating the Imperial Team (Player 2)
    for (int i = 0; i < numShips;i++) {
        m_enemyShips.enqueue(m_imperialShips[imperialRand]);
        //cout << "Imperial: " << imperialRand << endl;
        imperialRand = rand() % m_imperialShips.size();
    }

// cout << "Rebel" << endl;
//     for (int i = 0; i < m_myShips.size();i++) {
//         cout << *m_myShips[i] << " " << i << endl;
//     }
//     cout << "Imperial" << endl << endl << endl;
//     for (int i = 0; i < m_enemyShips.size();i++) {
//         cout << *m_enemyShips[i] << " " <<i << endl;
//     }
}

void StarWars::battle() {
    srand(time(NULL));
    int randStart = rand() % 2;

    // Rebel Team Starts first

        // Rework on this later since it's a test.
    while ((!m_myShips.isEmpty()) && (!m_enemyShips.isEmpty())) {

        if (randStart == REBEL_TEAM) {
        cout << "The Rebel " << *m_myShips[m_myShips.getFront()] << " attacks the Imperial " 
            << *m_enemyShips[m_enemyShips.getFront()] << "." << endl;
        if (m_myShips[m_myShips.getFront()]->attack(m_enemyShips.queueFront())) {
            cout << "The Imperial " << *m_enemyShips[m_enemyShips.getFront()] << " was destroyed." << endl;
            m_enemyShips.dequeue();
        } else {
            cout << "The Imperial " << *m_enemyShips[m_enemyShips.getFront()] << " was damaged." << endl;
        }
        }

        if (randStart == IMPERIAL_TEAM) {
        cout << "The Imperial " << *m_enemyShips[m_enemyShips.getFront()] << " attacks the Rebel " 
            << *m_myShips[m_myShips.getFront()] << "." << endl;
        if (m_enemyShips[m_enemyShips.getFront()]->attack(m_myShips.queueFront())) {
            cout << "The Rebel " << *m_myShips[m_myShips.getFront()] << " was destroyed." << endl;
            m_myShips.dequeue();
        } else {
            cout << "The Rebel " << *m_myShips[m_myShips.getFront()] << " was damaged." << endl;
        }
        }
    if (randStart == IMPERIAL_TEAM) {
        randStart = REBEL_TEAM;
    } else {
        randStart = IMPERIAL_TEAM;
    }
    }
    if (m_myShips.isEmpty()) {
        cout << "Imperial Won!!" << endl;
    }
    if (m_enemyShips.isEmpty()) {
        cout << "Rebel Wonnered!!" << endl;
    }
}





