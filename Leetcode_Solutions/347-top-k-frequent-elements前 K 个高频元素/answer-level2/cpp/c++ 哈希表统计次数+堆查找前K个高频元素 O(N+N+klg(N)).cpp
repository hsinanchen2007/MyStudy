```
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<int> topKFrequent(const vector<int> &nums, int k) {
        unordered_map<int, int> count;
        for (auto num : nums)
            count[num]++;
        using value_t = pair<int, int>;
        vector<value_t> container(count.begin(), count.end());
        auto comp = [](const value_t &v1, const value_t &v2) {return v1.second < v2.second;};
        make_heap(container.begin(), container.end(), comp);
        vector<int> result;
        for (int i = 0; i < k; ++i) {
            result.push_back(container.begin()->first);
            pop_heap(container.begin(), container.end() - i, comp);
        }
        return result;
    }
};

int main() {
    for (auto i : Solution().topKFrequent({5, 3, 1, 1, 1, 3, 5, 73, 1}, 3))
        cout << i << endl;
}

```
操作                    对应代码                                                   时间复杂度
遍历数组构建哈希表       `for (auto num : nums)count[num]++;`                       O(N)
构建堆                  `make_heap(container.begin(), container.end(), comp);`     O(N)
k次pop操作              `pop_heap(container.begin(), container.end() - i, comp);`  O(klg(N))
