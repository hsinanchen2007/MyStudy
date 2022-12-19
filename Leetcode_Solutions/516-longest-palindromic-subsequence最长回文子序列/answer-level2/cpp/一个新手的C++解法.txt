### 解题思路
从第i位到第j位的最长的回文子序列由以下三个要素决定
1. 从第i位到第j-1位的最长的回文子序列
2. 从第i+1位到第j位的最长的回文子序列
3. 从第i+1位到第j-1位的最长的回文子序列+2（如果s[i]==s[j]）
所以动态规划，本人爱好设start为i,设dis为j-i

### 代码

```cpp
class Solution {
public:
    static const int MAXLEN = 1001;
    int longestPalindromeSubseq(string s) {
        int len=s.length();
        int p[MAXLEN][MAXLEN]={{0}};

        for(int i=0;i<len;i++){
            for(int j=0;j<len;j++){
                p[i][j]=0;
            }
        }

        for(int dis=0;dis<len;dis++){
            for(int start=0;start+dis<len;start++){
                if(dis==0) p[dis][start]=1;
                else{
                    if(dis==1) p[dis][start]=(s[start]==s[start+dis]?2:1);
                    else{
                        int len1=p[dis-1][start];
                        int len2=p[dis-1][start+1];
                        int len3=(s[start]==s[start+dis]?2+p[dis-2][start+1]:p[dis-2][start+1]);
                        p[dis][start]=max(max(len1, len2),len3);
                    }
                }
            }
        }
        return p[len-1][0];
    }
};
```