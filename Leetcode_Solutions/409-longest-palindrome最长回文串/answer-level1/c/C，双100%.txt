### 解题思路
最长的回文串，最多有一个单数的字母，其他都得是双数，上代码。

### 代码

```c
int longestPalindrome(char * s){
    int* chars = (int *)malloc(sizeof(int) * 52);
    memset(chars, 0, sizeof(int) * 52);
    int length = strlen(s);
    if (length == 0) {
        return 0;
    }
    for (int i = 0; i < length; i++) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            chars[s[i] - 'a']++;
        } else if (s[i] >= 'A' && s[i] <= 'Z') {
            chars[s[i] - 'A' + 26]++;
        }
    }
    int count = 0;
    int singleUsed = false;
    for (int i = 0; i < 52; i++) {
        if (chars[i] % 2 == 0) {
            count += chars[i];
        } else if (!singleUsed) {
            count += chars[i];
            singleUsed = true;
        } else {
            count += chars[i] - 1;
        }
    }
    free(chars);
    return count;
}
```