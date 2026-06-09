### 解题思路
words 中的字符串按长度从大到小排序
检查每个单词是否是前一个单词的子串，如果是，还要检查是否是前一个单词的末尾。

用到了qsort，
```
int compare(char **a, char **b)
{
   //按长度排序, 从长到短
    return strlen(*b) - strlen(*a);
}

qsort(words, wordsSize, sizeof(char *), compare);
```
qsort 比较字符串数组：
```
int compare(const void *p, const void *q)
{
    return strcmp(*(char **)p, *(char **)q);
}

qsort(words, wordsSize, sizeof(char *), compare);
```

### 代码

```c
int compare(char **a, char **b)
{
   //按长度排序, 从长到短
    return strlen(*b) - strlen(*a);
}
int minimumLengthEncoding(char ** words, int wordsSize){
    if(words == NULL){
        return 0;
    }
    qsort(words, wordsSize, sizeof(char *), compare);
    
    
    char ret[100000] = {0};
    char *index = NULL;
    sprintf(ret, "%s#", words[0]);
    for(int i = 1; i < wordsSize; i++){
        index = strstr(ret, words[i]);
        if(index == NULL){
            strcat(ret, words[i]);
            strcat(ret, "#");
        } else {
            if(*(index + strlen(words[i])) != '#'){
                //当前字符串在结果中存在，但不是单词末尾，如abcd 与 bc， 必须为abcd#bc#
                strcat(ret, words[i]);
                strcat(ret, "#");
            }
        }
    }
    return strlen(ret);
}
```