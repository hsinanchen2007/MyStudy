1. 桶排序，时间复杂度为 O(n)，可以把出现了的数字放在正确的位置。
2. 为了避免转换下标的麻烦，在末尾插入一个0，排序后0会出现在首位。
[4,3,2,7,8,2,3,1,0]
会被排序为
[0,1,2,3,4,2,3,7,8]
3. 然后把不等于值的索引返回。
```c++
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        nums.push_back(0);
        for (int i = 0; i < nums.size(); ++i)
            while (nums[i] != nums[nums[i]])
                swap(nums[i], nums[nums[i]]);
        vector<int> ans;
        for (int i = 1; i < nums.size(); ++i)
            if (i != nums[i]) ans.push_back(i);
        return ans;
    }
};
```
