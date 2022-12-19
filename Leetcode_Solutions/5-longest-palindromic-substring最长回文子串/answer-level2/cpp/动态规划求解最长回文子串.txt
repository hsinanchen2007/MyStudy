### 解题思路

**！都是忘记写的：注意一下不要忘记遍历的过程中随时更新dp数组**
**本题的特点是，注意添加Start和max记录型变量**


### 代码

```cpp
class Solution {
public:
    string longestPalindrome(string s) {
       //动态规划
       int len=s.length();
       if(len<=1) return s;
       vector<vector<int>> dp(len,vector<int>(len,0));//len*len二维数组
       int start=0,max=1;
       for(int i=0;i<len;i++){//初始化dp数组
            dp[i][i]=1;
            if(i<len-1 && s[i]==s[i+1])
            {
                dp[i][i+1]=1;//!
                start=i;
                max=2;
            }
       }
       for(int l=3;l<=len;l++){
           for(int i=0;i+l-1<len;i++){
               int j=i+l-1;//子串结束位置
               if(s[i]==s[j] && dp[i+1][j-1]==1){
                   dp[i][j]=1;//!
                   start=i;
                   max=l;
               }
           }
       }
       return s.substr(start,max);
    }
};
```