#ifndef _MZ_TYPE_HPP_
#define _MZ_TYPE_HPP_

template<typename FirstType
, typename SecondType
>
struct Pair {
    using First_t = FirstType;
    using Second_t = SecondType;

    First_t first;
    Second_t second;

    Pair() {}

    Pair(const First_t& first, const Second_t& second)
        : first(first)
        , second(second) {}

    Pair(const Pair& other)
        : first(other.first)
        , second(other.second) {}

    Pair& operator =(const Pair& other) {
        if (this != &other) {
            first = other.first;
            second = other.second;
        }
        return *this;
    }
};

template<typename PairType
, typename CompareType
>
struct PairCompare {
    using Pair_t = PairType;
    using Compare_t = CompareType;

    Compare_t m_compare;

    int operator ()(const Pair_t& left, const Pair_t& right) const {
        return m_compare(left.first, right.first);
    }
};

#endif // _MZ_TYPE_HPP_
