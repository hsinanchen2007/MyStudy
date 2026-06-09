1. 题目中的波浪数组即为数组中的奇数位比相邻的偶数位的数字小，或者数组中的所有偶数位的数字比相邻的奇数位的数字小；
2. 我们只需要求出这两种变动方式下，数组的数需要变动的最小值；
3. 只需要求出，如果使得数组中的对应位的数变为比相邻的数都小的最小变动的值；

```c++ []
class Solution {
public:
    int movesToMakeZigzag(vector<int>& nums) {
        int ans1 = 0;
        int ans2 = 0;
        for(int i = 1;i < nums.size(); i += 2){
            int raise = 0;
            if(nums[i] >= nums[i-1]){
                raise = abs(nums[i]-nums[i-1]) + 1;
            }
            if(i+1 < nums.size()&& nums[i] >= nums[i+1]){
                raise = max(raise,abs(nums[i]-nums[i+1])+1);
            }
            ans1 += raise;
        }
        
        for(int i = 0;i < nums.size(); i += 2){
            int raise = 0;
            if(i > 0 && nums[i] >= nums[i-1]){
                raise = abs(nums[i]-nums[i-1]) + 1;
            }
            if(i+1 < nums.size()&& nums[i] >= nums[i+1]){
                raise = max(raise,abs(nums[i]-nums[i+1])+1);
            }
            ans2 += raise;
        }
        
        return min(ans1,ans2);
    }
};
```
```python []
class Solution:
    def movesToMakeZigzag(self, nums: List[int]) -> int:
        ans1 = 0
        ans2 = 0
        n = len(nums)
        
        idx = 0
        while idx < n:
            rest = 0
            if idx-1 >= 0 and nums[idx] >= nums[idx-1]:
                rest = max(rest,abs(nums[idx] - nums[idx-1])+1)
            if idx+1 < n  and nums[idx] >= nums[idx+1]:
                rest = max(rest,abs(nums[idx] - nums[idx+1])+1)
            ans1 += rest
            idx  += 2
        
        idx = 1
        while idx < n:
            rest = 0
            if idx-1 >= 0 and nums[idx] >= nums[idx-1]:
                rest = max(rest,abs(nums[idx] - nums[idx-1])+1)
            if idx+1 < n  and nums[idx] >= nums[idx+1]:
                rest = max(rest,abs(nums[idx] - nums[idx+1])+1)
            ans2 += rest
            idx  += 2
            
        return min(ans1,ans2)
```
```java []
class Solution {
    public int movesToMakeZigzag(int[] nums) {
        int ans1 = 0;
        int ans2 = 0;
        int n = nums.length;
        
        for(int i = 0; i < nums.length; i += 2){
            int rest = 0;
            if(i-1 >= 0 && nums[i] >= nums[i-1]){
                rest = Math.max(rest,Math.abs(nums[i]-nums[i-1])+1);
            }
            if(i+1 < n && nums[i] >= nums[i+1]){
                rest = Math.max(rest,Math.abs(nums[i]-nums[i+1])+1);
            }
            ans1 += rest;
        }
        for(int i = 1; i < nums.length; i += 2){
            int rest = 0;
            if(i-1 >= 0 && nums[i] >= nums[i-1]){
                rest = Math.max(rest,Math.abs(nums[i]-nums[i-1])+1);
            }
            if(i+1 < n && nums[i] >= nums[i+1]){
                rest = Math.max(rest,Math.abs(nums[i]-nums[i+1])+1);
            }
            ans2 += rest;
        }
        
        return Math.min(ans1,ans2);
    }
}
```
