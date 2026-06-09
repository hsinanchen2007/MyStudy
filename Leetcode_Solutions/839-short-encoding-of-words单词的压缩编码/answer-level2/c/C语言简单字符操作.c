### 解题思路
1.先按单词长度降序排序
2.输入最长的单词
3.每再输入一个单词与之前的单词比较是否已经包含

### 代码

```c
int minimumLengthEncoding(char ** words, int wordsSize){
    if (words == NULL) {
        return 0;
    }
    if (wordsSize == 1) {
        return strlen(words[0]) + 1;
    }

    int i = 0;
    int j = 0;
    char sortwords[2000][8] = {};
    char tempwords[8] = {};
    char *s = NULL;
    int *indexes = NULL;
    s = (char *)malloc(wordsSize * 8 + 1);

    //将words拷贝到sortwords中准备排序
    for(i = 0; i < wordsSize; i++) {
        strncpy(sortwords[i],words[i],strlen(words[i]) + 1);
    }

    //字符串按长度由长到短排序
    for (i = 0; i < wordsSize; i++) {
        for (j = i; j < wordsSize; j++) {
            if (strlen(sortwords[i]) < strlen(sortwords[j])) {
               strncpy(tempwords, sortwords[i], sizeof(sortwords[i]));
               strncpy(sortwords[i], sortwords[j], sizeof(sortwords[i]));
               strncpy(sortwords[j], tempwords, sizeof(sortwords[i])); 
            }
        }
    }

    //先放入最长的
    int length = strlen(sortwords[0]) + 1;
    //判断是否为字串
    int deita = 0;
    int issonstring = 0;
    for (i = 1; i < wordsSize; i++) {
        issonstring = 0;
        //判断是否是长单词的字串
        for (j = i - 1; j >= 0; j--) {
            deita = strlen(sortwords[j]) - strlen(sortwords[i]);
            if (strcmp(&sortwords[j][deita],sortwords[i]) == 0) {
               issonstring = 1; 
            }
        }
        //如果是字串不需要增加长度
        if (issonstring == 1) {
            continue;
        }
        length = length + strlen(sortwords[i]) + 1;        
    }
    free(s);
    free(indexes);
    return length;
}
```