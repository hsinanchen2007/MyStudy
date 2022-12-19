动态规划解决这道题。
考虑字符串S,长度为len。
S[0],...S[len-1]的字符串，有如下讨论：
1. S[0] == S[len-1]，则判断S[1]-S[len-2]即可。
2. 不相等时，则最小的插入长度 = min(S[1]-S[len-1], S[0]-S[len-2]) + 1， 即最后插入的和首尾中的一个对称，考虑剩下的即可。
3. 注意边界条件。

```
int minInsertions(string s) {
        int totalStrLength = s.length();
        int cntAdd[501][501] = {0};
        for(int len = 1; len <= totalStrLength; ++len){
            for(int i = 0; i < totalStrLength; ++i){
                int endPoint = i + len - 1;
                if(endPoint >= totalStrLength) break;
                if(len == 1) cntAdd[i][i] = 0;
                else if(len == 2) {
                    if(s[i] == s[endPoint]) cntAdd[i][endPoint] = 0;
                    else cntAdd[i][endPoint] = 1;
                }
                else {
                    if(s[i] == s[endPoint]) cntAdd[i][endPoint] = cntAdd[i+1][endPoint-1];
                    else cntAdd[i][endPoint] = min(cntAdd[i][endPoint-1], cntAdd[i+1][endPoint]) + 1;
                }
            }
        }
        return cntAdd[0][totalStrLength-1];
    }
```
