```
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
         int size = nums.size();
         int sum = 0;
         int ans = INT_MAX;
         for(int i=0,j=0;j<size;j++){
             sum = sum + nums[j];
             while(sum >= s){
                 ans = min(ans, j-i+1);
                 sum = sum - nums[i];
                 i += 1;
             }
         }
        return (ans==INT_MAX)?0:ans;
    }
};
```
这道题好奇怪，我已经是log(n)的解法了，可是运行时间才击败20%。我看了更快的人的解法，和我是完全一样的，不知道为啥。