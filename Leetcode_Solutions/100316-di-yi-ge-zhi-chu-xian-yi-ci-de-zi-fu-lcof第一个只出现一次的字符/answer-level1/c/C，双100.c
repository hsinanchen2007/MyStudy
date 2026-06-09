不知道为啥，看题解中的C解法都写的好复杂，感觉好像并没有那么复杂的样子，不知道是不是我考虑不周了。

```
char firstUniqChar(char* s){
    int hash[26] = {0};

    int len = strlen(s);    // 这里先求出strlen下面直接用，不建议再for循环的条件中写strlen，效率低了很多
    for (int i = 0; i < len; ++i) {
        ++hash[s[i] - 'a'];
    }

    for (int i = 0; i < len; ++i) {
        if (hash[s[i] - 'a'] == 1) {
            return s[i];
        }
    }

    return ' ';
}
```
