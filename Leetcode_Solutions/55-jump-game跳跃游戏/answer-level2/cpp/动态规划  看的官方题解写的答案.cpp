### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    
    bool canJump(vector<int>& nums) {
        if(nums.size()==0) return true;
        int dp[nums.size()];
        enum Index {GOOD,BAD,UNKONWED};
        memset(dp,UNKONWED,sizeof(dp));
        dp[nums.size()-1]=GOOD;
        int tmp;
        for(int i=nums.size()-2;i>=0;i--){
            tmp=min(int(nums.size()-1),i+nums[i]);//注意：min中使用长度要类型转化，不支持vector，只支持（int,int)
            for(int j=i+1;j<=tmp;j++){
                if(dp[j]==0){
                    dp[i]=GOOD;
                    break;
                }
            }
            if(dp[i]==UNKONWED) dp[i]=BAD;
        }
        if(dp[0]==GOOD) return true;
        return false;
    }
};
```