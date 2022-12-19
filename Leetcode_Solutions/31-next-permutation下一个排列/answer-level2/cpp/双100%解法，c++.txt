### 解题思路
此处撰写解题思路
从后往前找第一个相邻元素前比后小的值，下标位i，没找到就说明是降序，直接正排序返回
找到第一个符合条件元素下标i之后。找比他大的最小的元素，记录它的值，并且删除。
然后将i到最后的所有元素排序。并将刚才删除的值查到i的位置即可.
### 代码

```cpp
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size() == 0 || nums.size() == 1)
            return;
        for(int i = nums.size()  - 2; i >= 0 ;)
        {
            if((nums[i] == nums[i + 1]) || (nums[i] > nums[i + 1]))
            {
                i--;
                continue;
            }
            if(nums[i] < nums[i + 1])
            {
                int first_big = INT_MAX;
                int d_value = INT_MAX;
                int index = 0;
                for(int j = i + 1 ; j < nums.size() ; j++)
                    {
                        if(nums[j] <= nums[i])
                            break;
                        if(nums[j] - nums[i] < d_value)
                        {
                            d_value = nums[j] - nums[i];
                            first_big = nums[j];
                            index = j;
                        }
                    }
                nums.erase(nums.begin() + index);
                sort(nums.begin() + i , nums.end());
                nums.insert(nums.begin() + i,first_big);
                return ;
            }
        }
        sort(nums.begin(),nums.end());
        return;
    }
};
```