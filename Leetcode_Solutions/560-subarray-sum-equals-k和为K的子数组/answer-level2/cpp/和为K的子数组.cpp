### 解题思路
动态规划 dp[i]保存的是以i结束的子串合为0的个数

### 代码

```cpp
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int result=0;
        int n=nums.size();
        if(n==0){
            return 0;
        }
        vector<int> dp(n,0);
        if(nums[0]==k){
            result++;
            if(nums[0]==0){
                dp[0]=1;
            }
        }
        for(int i=1;i<n;i++){
            int temp=0;
            for(int j=i;j>=0;j--)
            {
                temp+=nums[j];
                if(temp==0)
                {
                    if(j==0){
                        dp[i]=1;
                        break;
                    }else{
                        dp[i]=dp[j-1]+1;
                        break;
                    }
                }
            }
            temp=0;
            for(int j=i;j>=0;j--){
                temp+=nums[j];
                if(temp==k)
                {
                    if(j==0){
                        cout<<1<<" ";
                        result++;
                        break;
                    }else{
                        cout<<dp[j-1]+1<<" ";
                        result=result+dp[j-1]+1;
                        break;
                    }
                }
            }
        }
        return result;

    }
};
```