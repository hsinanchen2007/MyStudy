### 解题思路
1.简单的hash思路，将chars中的字母出现的次数记录到hash表中；
2，每次遍历一个单词，如果在hash表中，并且满足要求
3.总的输出长度累加；

### 代码

```c
#define MAXNUM 26
int countCharacters(char ** words, int wordsSize, char * chars){
    int hash[MAXNUM] = {0};
    int hashtmp[MAXNUM] = {0};

    char *tmp = chars;
    while(*tmp) {
        hash[*tmp - 'a']++;
        tmp++;
    }

    int j;
    int count = 0;
    int flag;
    int i;
    for (j = 0; j < wordsSize; j++) {
        flag = 1;
        memcpy(hashtmp, hash,sizeof(int) * MAXNUM);
        for (i = 0; i < strlen(words[j]); i++) {
            hashtmp[words[j][i] - 'a']--;
            if (hashtmp[words[j][i] - 'a'] < 0)
                flag = 0;
        }
        if (flag == 1)
            count += i;
    }
   // printf("count %d\n",count);
    return count;
}
```