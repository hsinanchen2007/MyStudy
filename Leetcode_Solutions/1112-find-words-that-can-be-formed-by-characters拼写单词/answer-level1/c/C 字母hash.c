### 解题思路
构造字母哈希表，遍历匹配求和

### 代码

```c
int countCharacters(char ** words, int wordsSize, char * chars){
    int A_Z[26] = {0};
    int tmp[26] = {0};
    int length = 0;

    for (int i = 0; i < strlen(chars); i++) {
        A_Z[(int)(chars[i] - 'a')]++;
    }

    for (int i = 0; i < wordsSize; i++) {
        for (int n = 0; n < 26; n++) {
            tmp[n] = A_Z[n];
        }

        for (int j = 0; j < strlen(words[i]); j++) {
            int x = (int)(words[i][j] - 'a');
            tmp[x]--;
            if (tmp[x] < 0) {
                break;
            }
            printf("%c\n", words[i][j]);
            if (words[i][j + 1] == '\0') {
                length += j + 1;
            }
        }
    }

    return length;
}
```