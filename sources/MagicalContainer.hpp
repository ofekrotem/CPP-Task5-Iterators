#pragma once
#include <vector>

using namespace std;

namespace ariel{
class MagicalContainer {
public:
    class AscendingIterator; // forward declaration
    class SideCrossIterator; // forward declaration
    class PrimeIterator; // forward declaration
    // Default constructor
    MagicalContainer() {}

    // Methods for adding elements, removing elements, and retrieving the size of the container
    void addElement(int element); 
    void removeElement(int element);
    auto findPosition(const int element);
    int size() const;

    AscendingIterator begin_ascending() const;
    AscendingIterator end_ascending() const;
    
    SideCrossIterator begin_sidecross() const;
    SideCrossIterator end_sidecross() const;
    
    PrimeIterator begin_prime() const;
    PrimeIterator end_prime() const;
private:
    vector<int> elements;
};


class MagicalContainer::AscendingIterator {
public:
    AscendingIterator(const MagicalContainer& container, int current =0);
    AscendingIterator(const AscendingIterator& other);
    ~AscendingIterator();

    AscendingIterator& operator=(const AscendingIterator& other);

    bool operator==(const AscendingIterator& other) const;
    bool operator!=(const AscendingIterator& other) const;
    bool operator>(const AscendingIterator& other) const;
    bool operator<(const AscendingIterator& other) const;

    int operator*() const;

    AscendingIterator& operator++();

    AscendingIterator begin() const;
    AscendingIterator end() const;

private:
    int current;
    MagicalContainer container;
    void validateIncrement();
};

class MagicalContainer::PrimeIterator {
public:
    PrimeIterator(const MagicalContainer& container, int current =0);
    PrimeIterator(const PrimeIterator& other);
    ~PrimeIterator();

    PrimeIterator& operator=(const PrimeIterator& other);

    bool operator==(const PrimeIterator& other) const;
    bool operator!=(const PrimeIterator& other) const;
    bool operator>(const PrimeIterator& other) const;
    bool operator<(const PrimeIterator& other) const;

    int operator*() const;

    PrimeIterator& operator++();

    PrimeIterator begin() const;
    PrimeIterator end() const;

private:
    int  current;
    bool isPrime(int n) const;
    void validateIncrement();
    MagicalContainer container;
};

class MagicalContainer::SideCrossIterator {
public:
    SideCrossIterator(const MagicalContainer& container,int start=0, int finish =0);
    SideCrossIterator(const SideCrossIterator& other);
    ~SideCrossIterator();

    SideCrossIterator& operator=(const SideCrossIterator& other);

    bool operator==(const SideCrossIterator& other) const;
    bool operator!=(const SideCrossIterator& other) const;
    bool operator>(const SideCrossIterator& other) const;
    bool operator<(const SideCrossIterator& other) const;

    int operator*() const;

    SideCrossIterator& operator++();

    SideCrossIterator begin() const;
    SideCrossIterator end() const;

private:
    int start;
    int finish;
    MagicalContainer container;
    void validateIncrement();
};

}
