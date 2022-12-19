### 解题思路
1，把chars建一个数组cmap，保存每个字符的出现次数
2，遍历words的每一个词，如果词中某个字母在cmap中没计数或者计数用完了，则不满足

### 代码

```c
int countCharacters(char ** words, int wordsSize, char * chars){
    if (!words || wordsSize == 0 || !chars) return 0;

    int ans = 0;
    int cmap[26] = {0};
    for (int i = 0; i < strlen(chars); i++) {
        cmap[chars[i] - 'a'] ++;
    }

    for (int i = 0; i < wordsSize; i++) {
        int tmp[26];
        int j;
        memcpy(tmp, cmap, sizeof(cmap));
        for (j = 0; j < strlen(words[i]); j++) {
            if (tmp[words[i][j] - 'a'] == 0) break;
            tmp[words[i][j] - 'a']--;
        }
        if (j >= strlen(words[i])) ans += strlen(words[i]);
    }
    return ans;
}
```