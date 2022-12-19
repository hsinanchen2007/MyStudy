1. 在 index 中保存每个选手的序号，得分为 [5, 1, 2, 4, 3] 的选手，序号分别为 [0, 1, 2, 3, 4]。
2. 然后根据得分，对选手的序号排序，成绩大的排左边，得到排序后的序号序列 [0, 3, 4, 2, 1]，分别为第1，2，3，4，5名次的选手序号。
3. 把名次填进选手的序号。
```c++
class Solution {
public:
    vector<string> findRelativeRanks(const vector<int>& nums) {
        vector<int> index(nums.size());
        vector<string> ans(nums.size());
        iota(index.begin(), index.end(), 0);
        sort(index.begin(), index.end(), [&nums](const int& i, const int& j){
            return nums[j] < nums[i];
        });
        if (0 < nums.size()) ans[index[0]] = "Gold Medal";
        if (1 < nums.size()) ans[index[1]] = "Silver Medal";
        if (2 < nums.size()) ans[index[2]] = "Bronze Medal";
        for (int i = 3; i < nums.size(); ++i)
            ans[index[i]] = to_string(i + 1);
        return ans;
    }
};
```
