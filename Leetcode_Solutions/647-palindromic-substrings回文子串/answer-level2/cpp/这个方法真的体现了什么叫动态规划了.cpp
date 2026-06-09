### 解题思路
看注释,然后自己实验一遍就知道了,这是评论区大神的方法,这个方法在解题区里竟然没有上top3,实在是可惜,所以我要让它火！！
### 代码

```cpp
class Solution {
public:
//动态规划 dp[j]表示从j位置到当前遍历到的字符位置i是否为回文字符串
    int countSubstrings(string s) {
   int len=s.size();
   vector<int> dp(len);
   int cnt=0;
   for(int i=0;i<len;i++)
   {
       dp[i]=1;
       cnt++;
       for(int j=0;j<i;j++)
       {
           if(s[j]==s[i]&&dp[j+1]==1)
           {
               dp[j]=1;
               cnt++;
           }
           else dp[j]=0;
       }
   }return cnt;
    }
};
```