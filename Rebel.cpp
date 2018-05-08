#include "Rebel.h"

Rebel::Rebel(string name, string type, int attack, int defense)
   :Ship(name, type, attack, defense)
{  }

bool Rebel::attack(Ship* enemy) {
    int battleDef = enemy->getDefense();
    // Destroy if Rebel Attack is larger than Imperial Defence.
    if (getAttack() > enemy->getDefense()) {
        return 1;
    } 
    enemy->setDefense(battleDef - getAttack());
    return 0;
}

ostream& Rebel::toString(ostream& os) {
    os << getName();
    return os;
}
