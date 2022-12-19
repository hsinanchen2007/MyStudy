四数之和问题解法类似于三数之和的解法，只需在三数之和的基础上增加一层for循环即可。
具体思路：使用四个指针i，j，left，right。其中，i位置固定，j位置是i位置右侧的最左边的位置，即j=i+1，left为j的右侧的最左边位置，即left=j+1,right为最右侧位置，即right=nums.size()-1，然后移动left和right两个指针包夹求解。若nums[i]+nums[j]+nums[left]+nums[right]==target则保存于result中，否则fourSum > target时，right左移，即right--，fourSum < target时,left右移，即left++。当left和right重合时，表示以当前的i和j为最小值的解已经全部求得，从而j++,进入下一轮循环，当j循环结束后，进入最外层循环，即i++
时间复杂度：O(n^3)
空间复杂度：O(1)



### 代码

```cpp
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
         vector<vector<int>> result;
        if(nums.size() < 4) return result;
        sort(nums.begin(), nums.end(), )less<int>();//增序排序
        for(int i = 0; i < nums.size() - 3; i++)
        {
            if(i > 0 && nums[i - 1] == nums[i]) continue;//跳过重叠
            for(int j = i + 1; j < nums.size() - 2; j++)
            {
                if(j > i + 1 && nums[j] == nums[j - 1]) continue;//跳过重叠
                int left = j + 1, right = nums.size() - 1;
                while(left < right)
                     {
                int fourSum = nums[i] + nums[j] + nums[left] + nums[right];
                if(fourSum == target)
                {
                    result.push_back({nums[i],nums[j], nums[left], nums[right]});
                    while(left < right && nums[left] == nums[++left]);
                    while(left < right && nums[right] == nums[--right]); 
                }
                else (fourSum > target)? right-- : left++;
                 }
               }
            }
            
        return result;
    }
};
```