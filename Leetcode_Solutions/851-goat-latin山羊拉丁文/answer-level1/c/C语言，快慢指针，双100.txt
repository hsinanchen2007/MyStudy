### 解题思路
遍历一次字符串即可，对元音开头和辅音开头分别处理，每扫描一个词单词数+1，用于添加末尾的a

### 代码

```c
bool isYuanyin(char c)
{
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
        c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
            return true;
        }
    return false;
}
char * toGoatLatin(char * S){
    char *res = (char *)malloc(sizeof(char) * 10000);
    int cur = 0;
    char start;
    char ma[] = "ma";
    int count = 1;
    for (int i = 0; i < strlen(S);) {
        if (S[i] != ' ') {
            if (!isYuanyin(S[i])) {
                start = S[i];
                i++;
                while (i < strlen(S) && S[i] != ' ') {
                    res[cur++] = S[i++];
                }
                res[cur++] = start;
                res[cur++] = 'm';
                res[cur++] = 'a';
                for (int k = 0; k < count; k++) {
                    res[cur++] = 'a';
                }
                count++;
            } else {
                while (i < strlen(S) && S[i] != ' ') {
                    res[cur++] = S[i++];
                }
                res[cur++] = 'm';
                res[cur++] = 'a';
                for (int k = 0; k < count; k++) {
                    res[cur++] = 'a';
                }
                count++;
            }
        } else {
            res[cur++] = ' ';
            i++;
        }
    }
    res[cur] = '\0';
    return res;
}
```