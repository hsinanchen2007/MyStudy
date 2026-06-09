### 解题思路
此处撰写解题思路

### 代码

```c
#define MAXN 128
int longestPalindrome(char * s){
    int res[MAXN] = { 0 };
    int i = 0;
    while (s[i] != '\0') {
        res[s[i]- 'A']++;
        i++;
    }
    int result = 0;
    int hassingle = 0;
    for (int i = 0; i < MAXN;i++) {
        if (res[i] % 2 == 0) {
            result += res[i];
        }
        else if (res[i] %2 == 1) {
            result += (res[i] - 1);
            hassingle = 1;
        }
    }
    return result+hassingle;
}
```