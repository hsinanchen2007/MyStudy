先排除数组中不存在目标值的可能  存在的情况下left一定不会超过right 直接循环找就好
```
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
       if(find(nums.begin(),nums.end(),target)==nums.end())return {-1,-1};
      int left=0,right=nums.size()-1;
         while(nums[left]!=target)left++;
         while(nums[right]!=target)right--;
         return {left,right};
    }
};
```
