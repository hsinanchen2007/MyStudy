#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <deque>
#include <forward_list>
#include <list>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
#include <algorithm>
#include <functional>
#include <numeric>
#include <iterator>
#include <random>

using namespace std;

/*

https://en.cppreference.com/w/cpp/algorithm/sample

Selects n elements from the sequence [first; last) (without replacement) such that each possible sample 
has equal probability of appearance, and writes those selected elements into the output iterator out. 
Random numbers are generated using the random number generator g.

If n is greater than the number of elements in the sequence, selects last-first elements.

The algorithm is stable (preserves the relative order of the selected elements) only if PopulationIterator 
meets the requirements of LegacyForwardIterator

The behavior is undefined if out is in [first; last).

Return value
Returns a copy of out after the last sample that was output, that is, end of the sample range.

*/

int main()
{
    std::string in = "hgfedcba", out;
    std::sample(in.begin(), in.end(), std::back_inserter(out),
                5, std::mt19937{std::random_device{}()});
    std::cout << "five random letters out of " << in << " : " << out << '\n';

    return 0;
    // five random letters out of hgfedcba: gfcba
}
