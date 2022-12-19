### 解题思路
谢谢灵魂画师牧码的解题思路
通过先sort排序，然后使用左右指针的思路来选择出三数之和为0的成员。
当中要注意去掉重复成员和边界条件检查，以免出现越界。
这样时间复杂度可以从n的三次方变成了n的平方。


### 代码

```cpp
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> list;
        if ((nums.empty()) || (nums.size() < 3))
            return list;
        sort(nums.begin(), nums.end());
        vector<int> temp(3);
        int left = 0;
        int right = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > 0)
                break;
            /* remove the repeated elment */
            if ((i > 0) && (nums[i] == nums[i - 1]))
                continue;
                
            left = i + 1;
            right = nums.size() - 1;

            while (left < right)
            {
                if ((nums[i] + nums[left] + nums[right]) == 0)
                {
                     temp[0] = nums[i];
                     temp[1] = nums[left];
                     temp[2] = nums[right];
                     list.push_back(temp);
                     
                     /* repeated and boundary check */
                     while(((left + 1) < nums.size()) && (nums[left + 1] == nums[left]))
                         left++;
                    
                    /* repeated and boundary check */
                     while(((right - 1) >= 0) && (nums[right - 1] == nums[right]))
                         right--;
                    left++;
                    right--;
                }
                else if ((nums[i] + nums[left] + nums[right]) > 0)
                {
                    right--;
                }
                else if ((nums[i] + nums[left] + nums[right]) < 0)
                {
                    left++;
                }
            }

            
        }

        return list;

    }
};
```