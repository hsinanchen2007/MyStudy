### 解题思路
本题考虑使用**双指针+排序**方法解决，首先对给定的数组排序，然后设置left和right指针分别指向位置i的后续位置的最左侧和最右侧，threeSum = nums[i] + nums[left] + nums[right]，若threeSum > 0，为使其偏向0，则right--，否则left++
step1：首先，从题目描述入手，因要求三数之和，所以nums数组大小至少是3，即nums.size() < 3，返回空
step2：然后，对给定的nums数组按增序进行排序，即sort(nums.begin(), nums.end(), less<int>())
step3：最后，初始化left和right指针，即left = i + 1，right = nums.size() - 1，并求三数之和threeSum = nums[i] + nums[left] + nums[right]，判断threeSum是否满足等于0的条件，如果threeSum = 0，继续判断后一个元素是否等于当前元素，若相等，则持续向后循环判断，否则跳出当前循环。否则，若threeSum > 0，则right--，threeSum < 0，则left++
### 代码

```cpp
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;  //将三数和为0的三数以vector形式存储于result
        if(nums.size() < 3) return result;
        sort(nums.begin(), nums.end(), less<int>());
        for(int i = 0; i < nums.size() - 2; i++) 
        {
            if(nums[i] > 0) break; //因按照增序进行排序，所以若第1个元素大于0，则后面的数必定比第一个元素还要大，即不可能出现三数之和等于0，所以跳出循环
            if(i > 0 && nums[i - 1] == nums[i]) continue;  //判断前一元素是否等于当前元素，若相等，则跳过当前循环，进行下次循环，否则，确定三个数中的后两个数
            int left = i + 1, right = nums.size() - 1;
            while(left < right)
            {
                int threeSum = nums[i] + nums[left] + nums[right];
                if(threeSum == 0)
                {
                    result.push_back({nums[i], nums[left], nums[right]});  
                    while(left < right && nums[left] == nums[++left]);
                    while(left < right && nums[right] == nums[--right]); 
                    //ps：此处必须把++left或者--right，否则会在取值之后自加或自减
                }
                else (threeSum > 0)? right-- : left++;
            }
        }
        return result;
    }
};
```