### 解题思路
滑动窗口的解题思路，由于和小于sum时，r多往后移了一位，所以再计算长度时，直接计算R-L就可

### 代码

```cpp
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if(nums.size()<1) return 0;
        int l=0,r=0,sum=0;
        int res = nums.size()+1;
        while(l<nums.size()){
            if(sum>=s){
                res = min(res,r-l);    
            }
            if(sum < s && r < nums.size()){
                sum+=nums[r];
                r++;
            }else{
                sum-=nums[l];
                l++;
            }

            
        }
        if(res == nums.size()+1) return 0;
        return res;
    }
};
```