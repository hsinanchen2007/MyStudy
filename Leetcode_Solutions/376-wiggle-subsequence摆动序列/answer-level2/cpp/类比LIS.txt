### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> dp,data;
    int wiggleMaxLength(vector<int>& a) {
         int len=a.size();
         if(len==0)
          return 0;
         dp.resize(len);
         data.resize(len);
         for(int i=0;i<len;++i){
             dp[i]=1;
         }
         int mmax=1;
         for(int i=0;i<len;++i){
           for(int j=0;j<i;++j){
               if(dp[j]+1>dp[i]&&(a[j]-a[i]>0&&data[j]>=0||a[j]-a[i]<0&&data[j]<=0)){
                     dp[i]=dp[j]+1;
                     data[i]=a[i]-a[j];
               }
           }
           if(mmax<dp[i])
              mmax=dp[i];
         }
         return mmax;
    }
};
```