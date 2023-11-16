//
// Created by misha on 11/16/23.
//

#ifndef PM3PETTRNS_HERO_H
#define PM3PETTRNS_HERO_H

#include <string>
#include <sstream>

namespace game {

    enum class HeroType {
        SuperMan,
        CaptainRussia,
        SpiderMan
    };

    class Hero {
    public:
        explicit Hero(const std::string& name) : mName{name} {}

        [[nodiscard]] virtual std::string toString() const = 0;

        [[nodiscard]] std::string getName() const {
            return mName;
        }
        void setName(std::string& name) {
            mName = name;
        }

        static Hero* createHero(HeroType heroType, const std::string& name);

        virtual ~Hero() = default;
    protected:
        std::string mName;
    };

    class SuperMan : public Hero {
    public:
        explicit SuperMan(const std::string& name) : Hero(name) {}

        [[nodiscard]] std::string toString() const override {
            std::stringstream ss{};
            ss << "SuperMan: " << mName;
            return ss.str();
        }
    };

    class CaptainRussia : public Hero {
    public:
        explicit CaptainRussia(const std::string& name) : Hero(name) {}

        [[nodiscard]] std::string toString() const override {
            std::stringstream ss{};
            ss << "Captain Russia: " << mName;
            return ss.str();
        }
    };

    class SpiderMan : public Hero {
    public:
        explicit SpiderMan(const std::string& name) : Hero(name) {}

        [[nodiscard]] std::string toString() const override {
            std::stringstream ss{};
            ss << "Spider-man: " << mName;
            return ss.str();
        }
    };

    Hero* Hero::createHero(game::HeroType heroType, const std::string &name) {
        Hero* p;
        switch(heroType) {
            case HeroType::SuperMan:
                p = new SuperMan(name);
                break;
            case HeroType::CaptainRussia:
                p = new CaptainRussia(name);
                break;
            case HeroType::SpiderMan:
                p = new SpiderMan(name);
                break;
        }
        return p;
    }

} // game

#endif //PM3PETTRNS_HERO_H
