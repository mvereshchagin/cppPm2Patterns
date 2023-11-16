#include "Hero.h"
#include <iostream>
#include <vector>

int main() {
    using namespace game;

    std::vector<game::Hero*> heros{};
    heros.push_back(Hero::createHero(HeroType::SuperMan, "Володя"));
    heros.push_back(Hero::createHero(HeroType::CaptainRussia, "Инокентий"));
    heros.push_back(Hero::createHero(HeroType::SpiderMan, "Василий"));
    for(auto hero : heros) {
        std::cout << hero->toString() << std::endl;
    }

    return 0;
}
