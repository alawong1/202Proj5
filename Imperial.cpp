#include "Imperial.h"


Imperial::Imperial(string name, string type, int attack, int defense)
   :Ship(name, type, attack, defense)
{  }

bool Imperial::attack(Ship* enemy) {
    int battleDef = enemy->getDefense();
    // Destroy if Imperial Attack is larger than Rebel Defence.
    if (getAttack() > enemy->getDefense()) {
        return 1;
    }
    // Lower rebel defence if Imperial attack isn't large enough
    enemy->setDefense(battleDef - getAttack());
    return 0;
}

ostream& Imperial::toString(ostream& os) {
    os << getName();
    return os;
}