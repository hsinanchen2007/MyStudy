本题目跟46题相比，主要是增加了，在枚举当前层级的选集的时候，增加了一个去重，因为选择重复的数字，走出来是一条重复的路
```
class Solution {
public:
    vector<vector<int>> lists;
    vector<int> list;
    int numSize;
    vector<bool> used;
    void process(vector<int>& nums)
    {
        if (list.size() == numSize) {
            lists.push_back(list);
            return;
        }

        int loop;
        unordered_set<int> hashSet;
        for (loop = 0; loop < nums.size(); loop++) {
            if (!used[loop]) {
                if (hashSet.count(nums[loop])) {
                    continue;
                }
                list.push_back(nums[loop]);
                used[loop] = true;
                process(nums);
                used[loop] = false;
                hashSet.insert(nums[loop]);
                list.pop_back();
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        if (nums.size() == 0) {
            return lists;
        }
        numSize = nums.size();
        used.resize(numSize);
        process(nums);

        return lists;
    }
};
```
