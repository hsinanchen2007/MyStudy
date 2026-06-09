**粗体**### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int minCut(string s) {
        int n=s.length();
        int dp[n+1];
        dp[0]=-1;
        for(int i=1;i<=n;i++){
            dp[i]=i-1;
        }
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                string t= s.substr(i,j-i+1);
                if(huiwen(t)){
                    dp[j+1]=min(dp[j+1],dp[i]+1);
                }
                else{
                    dp[j+1]=min(dp[j+1],dp[j]+1);
                }
            }
        }
        return dp[n];
    }
    bool huiwen(string t){
        for(int i=0,j=t.length()-1;i<=j;i++,j--){
            if(t[i]!=t[j]){
                return false;
            }
        }
        return true;
    }
};
```