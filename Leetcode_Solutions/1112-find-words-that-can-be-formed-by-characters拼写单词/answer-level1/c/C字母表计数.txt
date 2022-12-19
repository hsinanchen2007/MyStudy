### 解题思路


### 代码

```c
#define LIMIT 27
int countCharacters(char ** words, int wordsSize, char * chars){
    char atable[LIMIT] = {0};
    int i = 0, index = 0, count = 0, j = 0;
    while(chars[i] != '\0'){
        index = chars[i] - 'a';
        //printf(" %c %d ",chars[i], index);
        atable[index]++;
        i++;
    }
    for(i = 0; i < wordsSize; i++){
        j = 0;
        char tmp[LIMIT] = {0};
        memcpy(tmp, atable, sizeof(char)*LIMIT);
        while(words[i][j] != '\0'){
            index = words[i][j] - 'a';
            if(tmp[index]== 0)
                break;
            tmp[index]--;
            j++;
        }
        if(words[i][j] == '\0')
            count += j;
    }
    return count;
}
```