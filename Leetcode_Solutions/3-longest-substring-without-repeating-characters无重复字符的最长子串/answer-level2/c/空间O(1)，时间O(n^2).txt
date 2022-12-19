# 解题思路


符号定义：

```xml
f(i): s[0]...s[i]的无重复字符的最长子串长度.
util(i): 以s[i]结尾的无重复字符最长子串。
```


f(i+1)有两种情况：

1. f(i+1) = f(i)
2. f(i+1) > f(i)


第一种情况， 最长字符可能包含s[i+1]； 第二种情况肯定包含s[i+1]。

因为要求最大长度，所以只关注第二种情况。

第二种情况中， 只需计算util（i+1）。而f(i+1)=len(util（i+1))=f(i)+1, f(i)可通过保存前一个计算的长度来计算。

```c
int lengthOfLongestSubstring(char * s){
    int sLen = strlen(s);
    int curLen = 0;
    int preLen = 0;
    int maxLen = 0;

    for (int i = 0; i < sLen; i ++) {
        curLen = 1;
        int j = i - 1;
        if (j >= 0) {
            int jLen = preLen;
            for (int k=j; (k>=0)&&(s[k]!=s[i])&&(k+preLen>j); k --) {
                curLen ++;
            }
        } 
        maxLen = maxLen>curLen?maxLen:curLen;
        preLen = curLen;
    }

    return maxLen;
}
```