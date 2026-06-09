### 解题思路
不同于其他人维护一个dp[i]等于到第i天为止最优的情况，

我维护的是dp[i]等于 在第i天选择按摩的条件下 最优的情况。

### 代码

```cpp
class Solution {
public:
    int massage(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }
        else if(nums.size()==1){
            return nums[0];
        }
        else if(nums.size()==2){
            return max( nums[0], nums[1]);
        }
        else if(nums.size()==3){
            return max( nums[0] + nums[2], nums[1]);
        }

        nums[2] += nums[0];
        
        for(int i= 3; i< nums.size(); i++){
            nums[i] = max(nums[i-2], nums[i-3] ) + nums[i]; // 既然第i天选择按摩，那么可以第i-2天选择按摩，
            //或者第i-3天选择按摩。
            //注意不能使用第i-4天选择按摩

            // 因为最长连续休息两天。
        }

        return max(nums[nums.size()-1], nums[nums.size()-2]);
        
        
    }
};
```