### 解题思路
此处撰写解题思路
换位思想
### 代码

```cpp
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> vec;

        int i = 0;
        while (i<nums.size())
            if (nums[i] != nums[nums[i]-1] && nums[i]-1 != i)
                swap(nums[i], nums[nums[i]-1]);
            else 
                i++;

        for (int i=0; i<nums.size(); i++)
            if (nums[i] != i+1)
                vec.push_back(i+1);

        return vec;
    }
};
```