##### 思路
- 类比最大子序和，`dp_max[i]`表示以i为结尾的连续最大乘积，但是会有负数的干扰，会出现最大值变为最小值的问题。
- 可以再设置最小值数组`dp_min[i]`，当`nums[i]<0`时，会出现最小值变最大值，最大值变最小值，因此可以得到递推表达式。
$$
dp\_max[i] = \begin{cases}
nums[0]&&i=0\\
max(dp\_max[i-1]*nums[i],nums[i])&&i>0,nums[i]>=0\\
max(dp\_min[i-1]*nums[i],nums[i])&&i>0,nums[i]<0\\
\end{cases}
$$
$$
dp\_min[i] = \begin{cases}
nums[0]&&i=0\\
min(dp\_min[i-1]*nums[i],nums[i])&&i>0,nums[i]>=0\\
min(dp\_max[i-1]*nums[i],nums[i])&&i>0,nums[i]<0\\
\end{cases}
$$
```cpp
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size()==1)return nums[0];
        vector<int> dp_max(nums.size(),0);//以i为结尾的最大乘积
        vector<int> dp_min(nums.size(),0);//以i为结尾的最小乘积
        dp_min[0] = nums[0],dp_max[0] = nums[0];
        int maxval = nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]<0){
                dp_min[i] = min(dp_max[i-1]*nums[i],nums[i]);
                dp_max[i] = max(dp_min[i-1]*nums[i],nums[i]);
            }
            else{
                dp_min[i] = min(dp_min[i-1]*nums[i],nums[i]);
                dp_max[i] = max(dp_max[i-1]*nums[i],nums[i]);
            }
            maxval = max(maxval, dp_max[i]);
        }
        return maxval;
    }
};
```