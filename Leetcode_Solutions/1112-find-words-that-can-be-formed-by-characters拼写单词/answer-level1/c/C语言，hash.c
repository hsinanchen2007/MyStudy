### 解题思路
使用字符hash

### 代码

```c
int countCharacters(char ** words, int wordsSize, char * chars){
    int chars_map[26] = {0};
    int chars_map_rsv[26] = {0};
    int i, j, tmp;
    int count = 0;

    for (i = 0; i < strlen(chars); i++) {
        chars_map[chars[i] - 'a']++;
    }

    memcpy(chars_map_rsv, chars_map, sizeof(int) * 26);

    for (i = 0; i < wordsSize; i++) {
        tmp = 0;
        //printf("t num is %d===========", chars_map_rsv[19]);
        memcpy(chars_map, chars_map_rsv, sizeof(int) * 26);
        for (j = 0; words[i][j] != '\0'; j++) {
            //printf("\t%c count is %d", words[i][j], chars_map[words[i][j] - 'a']);
            if (chars_map[words[i][j] - 'a'] == 0) {
                break;
            } else {
                chars_map[words[i][j] - 'a']--;
                tmp++;
                //printf("\t\t tmp = %d, i = %d", tmp, i);
            }
        }

        if (words[i][j] == '\0') {
            count += tmp;
        }
    }

    return count;
}
```