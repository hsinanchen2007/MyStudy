### 解题思路
思路是首先根据chars，搞一个全局的哈希表
然后遍历每个单词，给每个单词自己搞一个哈希表
一旦发现单词里面某个字母的数量超过了全局的哈希表，就认为该单词不可以拼成，不计数
完整遍历的单词即把它的长度加在结果上

### 代码

```c
#define MAX 128
int countCharacters(char ** words, int wordsSize, char * chars){
    if (words == NULL || wordsSize == 0 || chars == NULL) {
        return 0;
    }

    int dictSize = strlen(chars);
    int *dict = (int *)malloc(sizeof(int) * MAX);
    memset(dict, 0, MAX);
    for (int i = 0; i < dictSize; i++) {
        dict[(int)chars[i]]++;
    }

    int res = 0;
    for (int k = 0; k < wordsSize; k++) {
        int wordLength = strlen(words[k]);
        int flag = 1;
        int *wordDict = (int *)malloc(sizeof(int) * MAX);
        memset(dict, 0 , MAX);
        for (int j = 0; j < wordLength; j++) {
            wordDict[(int)words[k][j]]++;
            if (wordDict[(int)words[k][j]] > dict[(int)words[k][j]]) {
                flag = 0;
                break;
            }
        }
        free(wordDict);
        if (flag == 1) {
            res += wordLength;
        }
    }

    free(dict);
    return res;
}
```