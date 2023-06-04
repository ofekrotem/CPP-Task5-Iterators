#include "doctest.h"
#include "sources/MagicalContainer.hpp"

using namespace ariel;

TEST_CASE("Test addElement()") {
    MagicalContainer mc;
    mc.addElement(1);
    CHECK(mc.size() == 1);
    mc.addElement(5);
    CHECK(mc.size() == 2);
    mc.addElement(3);
    CHECK(mc.size() == 3);
}

TEST_CASE("Test removeElement()") {
    MagicalContainer mc;
    mc.addElement(1);
    mc.addElement(5);
    mc.addElement(3);
    mc.removeElement(5);
    CHECK(mc.size() == 2);
    mc.removeElement(1);
    CHECK(mc.size() == 1);
}

TEST_CASE("Test AscendingIterator") {
    MagicalContainer mc;
    mc.addElement(3);
    mc.addElement(1);
    mc.addElement(2);
    auto it = mc.begin_ascending();
    CHECK(*it == 1);
    ++it;
    CHECK(*it == 2);
    ++it;
    CHECK(*it == 3);
}

TEST_CASE("Test SideCrossIterator") {
    MagicalContainer mc;
    mc.addElement(3);
    mc.addElement(1);
    mc.addElement(2);
    auto it = mc.begin_sidecross();
    CHECK(*it == 1);
    ++it;
    CHECK(*it == 3);
    ++it;
    CHECK(*it == 2);
}

TEST_CASE("Test PrimeIterator") {
    MagicalContainer mc;
    mc.addElement(3);
    mc.addElement(4);
    mc.addElement(5);
    mc.addElement(8);
    mc.addElement(11);
    auto it = mc.begin_prime();
    CHECK(*it == 3);
    ++it;
    CHECK(*it == 5);
    ++it;
    CHECK(*it == 11);
}

TEST_CASE("Test iterator equality") {
    MagicalContainer mc;
    mc.addElement(1);
    mc.addElement(2);
    mc.addElement(3);
    CHECK(mc.begin_ascending() == mc.begin_ascending());
    CHECK(mc.begin_prime() == mc.begin_prime());
    CHECK(mc.begin_sidecross() == mc.begin_sidecross());
}

TEST_CASE("Test iterator inequality") {
    MagicalContainer mc;
    mc.addElement(1);
    mc.addElement(2);
    mc.addElement(3);
    CHECK(mc.begin_ascending() != mc.end_ascending());
    CHECK(mc.begin_prime() != mc.end_prime());
    CHECK(mc.begin_sidecross() != mc.end_sidecross());
}
