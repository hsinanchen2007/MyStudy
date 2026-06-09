### 解题思路
此处撰写解题思路
字符串中如果某个字母出现为偶数次，那么肯定可以构成回文数，则加上偶数次
如果出现次数为奇数次，那么如果该数大于1，则加上其对2相除再相乘。
所有相加之后再加1.然后判断最终的数是否大于字符串的长度。如果大于则为字符串长度。否则就是相加的数。

### 代码

```c
int longestPalindrome(char * s){
    int characters[127] = {0};
    int cnt = 0;
    for(int i = 0; i < strlen(s); i++)
    {
        characters[s[i]]++;
    }
    for(int i = 0; i < 127; i++)
    {
        if(characters[i] / 2 >= 1)
            cnt = characters[i] / 2 * 2 + cnt;
    }
    cnt++;
    if(cnt > strlen(s))
        return strlen(s);
    else
        return cnt;
}
```