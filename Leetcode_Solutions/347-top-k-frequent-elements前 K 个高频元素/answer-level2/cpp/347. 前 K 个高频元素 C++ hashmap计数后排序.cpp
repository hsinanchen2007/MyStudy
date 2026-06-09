### 解题思路
hashmap 计数后，重新赋值在vector中按出现次数排序，然后取前K个

### 代码

```cpp
class Solution {
public:
    static bool myfun(pair<int, int> a, pair<int, int> b)
    {
        if (a.second > b.second) {
            return true;
        }

        return false;
    }

    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> countmap;
        vector<pair<int, int>> numscount;
        vector<int> result;
        for (auto num : nums) {
            countmap[num]++;
        }

        for (auto count : countmap) {
            numscount.push_back(count);
        }

        sort(numscount.begin(), numscount.end(), myfun);

        for (int i = 0; i < k; i++) {
            result.push_back(numscount[i].first);
        }

        return result;
    }
};
```