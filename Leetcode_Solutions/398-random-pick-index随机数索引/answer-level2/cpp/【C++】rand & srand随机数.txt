```
#include <map>
#include <vector>
#include <cstdlib>

class Solution {
public:
    Solution(vector<int>& nums)
    {
        buildCollections(nums);
    }

    void buildCollections(const vector<int>& nums)
    {
        auto i = 0;
        for (auto iter = nums.begin();
                iter != nums.end();
                ++iter, ++i) {
            collections[*iter].push_back(i);
        }
    }

    int pick(int target)
    {
        auto finder = collections.find(target);
        if (finder != collections.end()) {
            auto size = finder->second.size();
            auto index = rand() % size;
            return finder->second.at(index);
        }
        return -1;
    }
private:
    map<int, vector<int>> collections;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
```
