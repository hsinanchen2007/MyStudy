### 解题思路
分第一间偷&最后一间不偷；第一间不偷&最后一间偷 这两种情况，返回最大值即可

### 代码

```cpp
class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        if(n==1) return nums[0];
        vector<int>dp1(n,0);
        vector<int>dp2(n,0);
        dp1[0]=nums[0];//第一间偷
        dp1[1]=max(dp1[0],nums[1]);
        dp2[0]=0;//第一间不偷
        dp2[1]=nums[1];
        for(int i=2;i<n;i++){
            dp1[i]=max(dp1[i-1],dp1[i-2]+nums[i]);
            dp2[i]=max(dp2[i-1],dp2[i-2]+nums[i]);
        }
        return max(dp1[n-2],dp2[n-1]);
    }
};
```