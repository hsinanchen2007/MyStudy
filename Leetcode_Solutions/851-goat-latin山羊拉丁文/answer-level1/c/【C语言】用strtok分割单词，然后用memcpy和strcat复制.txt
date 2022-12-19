用strtok分割单词，然后用memcpy和strcat复制
1.判断首字母是否元音时，统计转换为小写字母再判断；
2.记得去掉处理最后一个单词而引入的空格


```
#include <string.h>
#define MAX_LEN 10000

bool isVowel(char c)
{
    // 将c统一转换成小写字符，再判断
    if (c < 'a') {
        c = c + 32;
    }

    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}


char * toGoatLatin(char * S)
{
    int len = strlen(S);
    if (S== NULL || len == 0 || len > 150) {
        return NULL;
    }

    // 返回字符串
    char* goatLatin = (char*)malloc(MAX_LEN * sizeof(char));
    memset(goatLatin, 0, MAX_LEN * sizeof(char));
    int i = 0;  // 返回字符串的指针

    // 分隔S中的每个单词，遇到每个单词的开头就进行判断及处理
    char* ma = "ma";
    char delim[2] = " ";  // 单词分隔符
    char* word = NULL;  // 每个单词
    int wordIndex = 0;  // 每个单词在句子中的索引（从1开始）
    int wordLen;   //  每个单词的长度

    word = strtok(S, delim);

    while (word) {
        wordIndex++;  // 每个单词的索引
        wordLen = strlen(word);

        if (isVowel(word[0])) {  // 元音开头
            memcpy(goatLatin + i, word, wordLen);  // 将单词复制过去
            strcat(goatLatin + i, ma);  // 添加"ma"
        } else {  // 辅音开头
            memcpy(goatLatin + i, word + 1, wordLen - 1) ;
            goatLatin[i + wordLen - 1] = word[0];  // 首字母
            strcat(goatLatin + i, ma);  // 添加"ma"
        }

        i += wordLen + 2;  // 指针往后移动单词长度+“ma”’的长度

        // 添加与索引相同数量的字母'a'，索引从1开始。
        for (int j = 0; j < wordIndex; j++) {
            goatLatin[i++] = 'a';
        }

        // 添加空格
        goatLatin[i++] = ' ';

        // 继续提取
        word = strtok(NULL, delim);  
    }

    // 去掉处理完最后一个单词引入的空格
    goatLatin[i - 1] = '\0';

    return goatLatin;
}
```
