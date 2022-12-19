leetcode刷题经验告诉我，基本上所有的字符串的题都可以用DP解决，所以此题也不例外，接下来就分析一下解题过程。
动态规划最重要的就是找到状态转移方程，举两个例子（可能会有错误，自己手画的，非程序生成）
```
	r	a	b	b	b	i	t
r	1	1	1	1	1	1	1
a	0	1	1	1	1	1	1
b	0	0	1	2	3	3	3
b	0	0	0	1	3	3	3
i	0	0	0	0	0	3	3
t	0	0	0	0	0	0	3


	b	a	b	g	b	a	g
b	1	1	2	2	3	3	3
a	0	1	1	1	1	4	4
g	0	0	0	1	1	1	5

```
`dp[i][j]`表示`s[:i+1]`中包含`t[:j+1]`的个数
由上述转移过程我们不难发现其中的转移方程：
- `t[i]!=s[j]  dp[i][j]=dp[i][j-1]`
- `t[i]==s[j]  dp[i][j]=dp[i-1][j]+dp[i][j-1]`
接下来就是二维dp解法
```
// class Solution {
// public:
//     int numDistinct(string s, string t) {
//         if(t.size()==0)return 1;
//         if(s.size()==0)return 0;
//         long dp[t.size()+1][s.size()+1]={0};
//         dp[0][0]=1;
//         for(int i=1;i<=t.size();i++){
//             for(int j=i;j<=s.size();j++){
//                 if(i==1 && t[i-1]==s[j-1]){
//                     dp[i][j]=dp[i][j-1]+1;
//                     continue;
//                 }
//                 if(t[i-1]==s[j-1])dp[i][j]=dp[i][j-1]+dp[i-1][j-1];
//                 else dp[i][j]=dp[i][j-1];
//             }
//         }
//         return dp[t.size()][s.size()];
//     }
// };
```
通过上述过程我们发现，我们用到的只有`dp[i-1][j]`和`dp[i-1][j-1]`,这就造成了空间浪费，而一维DP需要保存一个临时值，大概像这样
```
class Solution {
public:
    int numDistinct(string s, string t) {
        if(t.size()==0)return 1;
        if(s.size()==0 || s.size()<t.size())return 0;
        vector<long>dp(s.size()+1,1);
        long pre = 1;
        for(int i = 1; i <= t.size(); i++){
            for(int j = 0; j <= s.size(); j++){
                long temp=dp[j];//保存本轮dp[j],用于本轮循环结束赋值给pre
                if(j == 0){
                    dp[0]=0;
                }else
                    t[i-1] == s[j-1] ? dp[j] = dp[j-1] + pre : dp[j] = dp[j-1];
                pre = temp;//此时的pre相当于dp[i-1][j-1]
            }
            
        }
        return dp[s.size()];
    }
};
```
或者完全不保存临时值，像这样

```
class Solution {
public:
    int numDistinct(string s, string t) {
        if(t.size()==0)return 1;
        if(s.size()==0 || s.size()<t.size())return 0;
        vector<long>dp(t.size()+1,0);
        dp[0]=1;
        for(int i=1;i<=s.size();i++){
            for(int j=t.size();j>0;j--){
                if(t[j-1]==s[i-1])dp[j]+=dp[j-1];
            }
        }
        return dp[t.size()];
    }
};
```

小网站上线了，大家也可以戳进来看看啦[李一平](https://liyiping.cn/)
