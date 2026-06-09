观察题目，发现题中所求字符串有三个要求：
1. s字典序大于等于s1
2. s字典序小于等于s2
3. s不包含evil

设计DP状态来表示这三个要求，F[i][j][k=0/1][l=0/1]表示：
已经构造了s的前i个字符，
且匹配到evil的前j个字符；
k=0表示字典序已经比s1大，k=1表示字典序等于s1的前i个字符组成的前缀
l同理。

考虑主动转移，即现在状态是F[i][j][k][l],枚举下一个字符a，看看能否转移到F[i+1][p][x][y]：
这三个状态转移是分开的。
j->p的转移相当于字符串匹配，用kmp处理，当p=m时，这个状态就非法了，就不管了。
考虑k的转移，l同理：
1. k=0,则x=0
2. k=1
若a==s1[i],x=1
若a>s1[i],x=0
若a<s1[i],非法

ps:代码中所用符号与题解不同
```
class Solution {
public:
    int findGoodStrings(int n, string s1, string s2, string evil) {
        for (int i=0;i<n;++i)
            if (s1[i]<s2[i]) break;
            else if (s1[i]>s2[i]) return 0;
        int MOD=1e9+7;
        long long F[510][51][2][2];
        int m=evil.size();
        memset(F,0,sizeof F);
        int Next[100];
        Next[0]=-1;
        for (int i=0,j=-1;i<m;)
        {
            if (j==-1 || evil[i]==evil[j]) ++i,++j,Next[i]=j;
            else j=Next[j];
        }
        int a,b;
        a=s1[0]-'a';
        b=s2[0]-'a';
        for (int i=0;i<26;++i)
        {
            if (i<a || i>b) continue;
            bool f1=false,f2=false;
            if (i==a) f1=true;
            if (i==b) f2=true;
            int p=0;
            if (i==evil[0]-'a') p=1;
            if (p==m) continue;
            F[1][p][f1][f2]++;
        }
        for (int i=1;i<n;++i)
        {
            a=s1[i]-'a';
            b=s2[i]-'a';
            for (int j=0;j<26;++j)
                for (int k=0;k<m;++k)
                {
                    int p=k;
                    while (p!=-1)
                    {
                        if (evil[p]-'a'==j) {++p;break;}
                        p=Next[p];
                    }
                    if (p==-1) p=0;
                    if (p==m) continue;
                    for (int f1=0;f1<2;++f1)
                        for (int f2=0;f2<2;++f2)
                        {
                            int x,y;
                            if (f1==0) x=0;
                            else
                            {
                                if (j==a) x=1;
                                else if (j>a) x=0;
                                else continue;
                            }
                            if (f2==0) y=0;
                            else
                            {
                                if (j==b) y=1;
                                else if (j<b) y=0;
                                else continue;
                            }
                            F[i+1][p][x][y]+=F[i][k][f1][f2];
                        }
                }
            for (int k=0;k<m;++k)
                for (int x=0;x<2;++x)
                    for (int y=0;y<2;++y)
                        F[i+1][k][x][y]%=MOD;
        }
        long long Ans=0;
        for (int i=0;i<m;++i)
        {
            Ans+=F[n][i][0][0];
            Ans+=F[n][i][0][1];
            Ans+=F[n][i][1][0];
            Ans+=F[n][i][1][1];
        }
        Ans%=MOD;
        return (int)Ans;
    }
};
```
