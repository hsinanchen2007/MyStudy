思路：动态规划，
dp[i][j]表示word1从0到i的子序列，word2从0到j的子序列，进行编辑距离的最少操作次数。
用一个例子说明，word1=abe,word2=abc

如果word1[i]==word1[j],dp[i][j]=dp[i-1][j-1]
比如i=2,j=2,此时word1=ab,word2=ab,新的字符都是b相同，那么相当于不用操作，加上a和a的操作数。

如果word1[i]!=word1[j],此时可以使用增删改三种操作中的一个
这里使用i=3,j=3,word1=abe,word2=abc
如果改，就是abe->abc,即e改c，操作一次，然后相当于ab和ab即dp[i-1][j-1]+1
如果删，就是abe->ab,删掉e，操作一次，然后相当于ab和abc即dp[i-1][j]+1
如果增，就是abe->abec,添加c，操作一次，然后相当于abe和ab的子问题，即 dp[i][j-1]+1

```
#include "leetcode.h"


class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1=word1.length(),len2=word2.length();
        int dp[len1+1][len2+1];
        for(int i=0;i<=len1;i++)dp[i][0]=i;
        for(int j=0;j<=len2;j++)dp[0][j]=j;


        for(int i=1;i<=len1;i++){
            for(int j=1;j<=len2;j++){
                if(word1[i-1]==word2[j-1])dp[i][j]=dp[i-1][j-1];
                else {
                    int temp = min(dp[i-1][j-1],dp[i-1][j]);
                    temp = min(dp[i][j-1],temp);
                    dp[i][j]=temp+1;
                }
                printf("(%d,%d)=%d\n",i,j,dp[i][j]);
            }
        }
        return dp[len1][len2];
    }
};


int main(){
    Solution s;
    // string str1="horse",str2="ros";
    string str1="intention",str2="execution";
    int ans = s.minDistance(str1,str2);
    cout<<ans<<endl;
    return 0;
}
```

