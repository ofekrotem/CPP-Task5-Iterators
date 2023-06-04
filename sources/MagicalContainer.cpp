#include "MagicalContainer.hpp"
#include <algorithm>
#include <cmath>

using namespace std;

namespace ariel{
auto MagicalContainer::findPosition(const int element){
    return upper_bound(elements.begin(),elements.end(),element);
}

void MagicalContainer::addElement(int element) {
    elements.insert(findPosition(element), element);
}


void MagicalContainer::removeElement(int element) {
    elements.erase(std::remove(elements.begin(), elements.end(), element), elements.end());
}

int MagicalContainer::size() const {
    return elements.size();
}

MagicalContainer::AscendingIterator MagicalContainer::begin_ascending() const {
    return AscendingIterator(*this);
}

MagicalContainer::AscendingIterator MagicalContainer::end_ascending() const {
    return AscendingIterator(*this, true);
}

MagicalContainer::SideCrossIterator MagicalContainer::begin_sidecross() const {
    return SideCrossIterator(*this);
}

MagicalContainer::SideCrossIterator MagicalContainer::end_sidecross() const {
    return SideCrossIterator(*this, true);
}

MagicalContainer::PrimeIterator MagicalContainer::begin_prime() const {
    return PrimeIterator(*this);
}

MagicalContainer::PrimeIterator MagicalContainer::end_prime() const {
    return PrimeIterator(*this, true);
}


MagicalContainer::AscendingIterator::AscendingIterator(const MagicalContainer& container, int current) 
: current(current), container(container) {}

MagicalContainer::AscendingIterator::AscendingIterator(const AscendingIterator& other)
    : container(other.container), current(other.current){}

MagicalContainer::AscendingIterator::~AscendingIterator() {}

MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator=(const AscendingIterator& other) {
    current = other.current;
    container = other.container;
    return *this;
}

bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator& other) const {
    return current == other.current;
}

bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator& other) const {
    return current != other.current;
}

bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator& other) const {
    return current > other.current;
}

bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator& other) const {
    return current < other.current;
}

int MagicalContainer::AscendingIterator::operator*() const {
    return container.elements[(vector<int>::size_type)current];
}

MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator++() {
    ++current;
    return *this;
}

MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin() const {
    return AscendingIterator(this->container, 0);
}

MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end() const {
    return AscendingIterator(this->container, this->container.size());
}

MagicalContainer::PrimeIterator::PrimeIterator(const MagicalContainer& container, int current) 
: current(current), container(container) {
    while(this->current < this->container.size()){
        if(isPrime(container.elements[(vector<int>::size_type)current]))
            break;
        current++;
    }
}

MagicalContainer::PrimeIterator::PrimeIterator(const PrimeIterator& other)
    : current(other.current), container(other.container) {}

MagicalContainer::PrimeIterator::~PrimeIterator() {}

MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator=(const PrimeIterator& other) {
    container = other.container;
    current = other.current;
    return *this;
}

bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator& other) const {
    return current == other.current;
}

bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator& other) const {
    return current != other.current;
}

bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator& other) const {
    return current > other.current;
}

bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator& other) const {
    return current < other.current;
}

int MagicalContainer::PrimeIterator::operator*() const {
    return container.elements[(vector<int>::size_type)current];
}

MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator++() {
    do{
        current++;
        if(isPrime(container.elements[(vector<int>::size_type)current]))
            break;
    } while(this->current < this->container.size());
    return *this;
}

bool MagicalContainer::PrimeIterator::isPrime(int n) const {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i <= sqrt(n); ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin() const {
    return PrimeIterator(this->container, 0);
}

MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end() const {
    return PrimeIterator(this->container, this->container.size());
}

MagicalContainer::SideCrossIterator::SideCrossIterator(const MagicalContainer& container, int start, int finish)
    : container(container), start(start), finish(finish) {}

MagicalContainer::SideCrossIterator::SideCrossIterator(const SideCrossIterator& other)
    : container(other.container), start(other.start),finish (other.finish) {}

MagicalContainer::SideCrossIterator::~SideCrossIterator() {}

MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator=(const SideCrossIterator& other) {
    container = other.container;
    start = other.start;
    finish = other.finish;
    return *this;
}

bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator& other) const {
    return (start == other.start && finish == other.finish);
}

bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator& other) const {
    return !(*this == other);
}

bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator& other) const {
    return (start > other.start || finish > other.finish);
}

bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator& other) const {
    return (start < other.start || finish < other.finish);
}

int MagicalContainer::SideCrossIterator::operator*() const {
    if(start == finish)
        return container.elements[(vector<int>::size_type)start];
    return container.elements[(vector<int>::size_type)(container.size()-finish)];

}

MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator++() {
    if (start == finish) {
        ++finish;
    } else {
        ++start;
    }
    return *this;
}

MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin() const {
    return SideCrossIterator(this->container);
}

MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end() const {
    int middle = container.size()/2;
    if(container.size()%2==0)
        return SideCrossIterator(this->container, middle,middle);
    return SideCrossIterator(this->container, middle, middle+1);
}
}
