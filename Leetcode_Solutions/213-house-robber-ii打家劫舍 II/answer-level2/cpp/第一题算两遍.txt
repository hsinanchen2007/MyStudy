### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int dp(vector<int> nums,int st,int ed){
        int n=nums.size();
        if(n==0) return 0;
        if(n==1) return nums[0];
        int cur_max=0;
        int pre_max=0;
        for(int i=st;i<ed;++i){
            int tmp=cur_max;
            cur_max=max(pre_max+nums[i],cur_max);
            pre_max=tmp;     
        }
        return cur_max;
    };
    int rob(vector<int>& nums) {

        return max(dp(nums,0,nums.size()-1),dp(nums,1,nums.size()));

    }
};
```