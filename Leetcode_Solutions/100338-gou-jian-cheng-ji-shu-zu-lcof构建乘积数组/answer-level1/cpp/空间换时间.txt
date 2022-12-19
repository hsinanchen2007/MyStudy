### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        vector<int> df(a.size(),0);
        vector<int> dp(a.size(),0);
        for(int i=0;i<a.size();i++){
            if(i==0)df[i]=a[i];
            else df[i]=df[i-1]*a[i];
        }
        for(int i=a.size()-1;i>=0;i--){
            if(i==a.size()-1)dp[i]=a[i];
            else dp[i]=a[i]*dp[i+1];
        }
        vector<int> ans(a.size(),0);
        for(int i=0;i<a.size();i++){
            if(i==0)ans[i]=dp[1];
            else if(i==a.size()-1)ans[i]=1*df[i-1];
            else ans[i]=df[i-1]*dp[i+1];
        }
        return ans;
    }

};
```