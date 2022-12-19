### 解题思路

### 代码

```cpp
#define MAX_INF 100000
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int>vdp((int)nums.size()+1,-(MAX_INF));
        int idx=1,ans=-(MAX_INF),sz=nums.size();
        for(int i=0;i<sz;++i){
            vdp[idx]=max(nums[i],vdp[idx-1]+nums[i]);
            if(i)
                vdp[idx]=max(vdp[idx],vdp[idx-2]+nums[i-1]+nums[i]);
            ans=max(vdp[idx++],ans);
        }
        return ans;
    }
};
```