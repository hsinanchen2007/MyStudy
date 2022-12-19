### 解题思路
1、先将词根按照字典树保存起来；
2、以空格是分割，获取到每一个单词；
3、单词在字典树中查找，找到则返回长度，找不到返回0；
4、没一个单子将替换的结果保存到result的字符串中，0表示没有找到，全部复制进去；

注意点：
1、最后一个词是跳出循环的，需要单独处理下；
2、结果的字符串长度要足够大，1000*1000；
3、释放内存。

### 代码

```c

struct dictmap {
    int isEnd;
    struct dictmap* map[26];
};

void addToDictMap(char* dictItem, int index, struct dictmap* hash)
{
    char temp = *(dictItem + index);
    if (temp == '\0') {
        hash->isEnd = 1;
        return;
    }

    if (hash->map[temp - 'a'] == NULL) {
        hash->map[temp - 'a'] = (struct dictmap *)malloc(sizeof(struct dictmap));
        memset(hash->map[temp - 'a'], 0 , sizeof(struct dictmap));
    }

    addToDictMap(dictItem, index + 1, hash->map[temp - 'a']);

    return;
}

void getRootChar(char* sentenceItem, struct dictmap* hash, int* outLen)
{
    char current = *(sentenceItem + *outLen);
    if (current == '\0') {
        return;
    }
    if (hash->map[current - 'a'] == NULL) {
        *outLen = 0;
        return;
    } else if (hash->map[current - 'a']->isEnd == 1) {
        (*outLen)++;
        return;
    }
    (*outLen)++;
    getRootChar(sentenceItem, hash->map[current - 'a'], outLen);

    return;
}

void freeHash(struct dictmap* hash)
{
    int i = 0;
    for (i = 0; i < 26; i++) {
        if (hash->map[i] != NULL) {
            freeHash(hash->map[i]);
        }
    }
    free(hash);
    return;
}
char * replaceWords(char ** dict, int dictSize, char * sentence){
    int i = 0;
    struct dictmap hashHead = {0};

    for (i = 0; i < dictSize; i++) {
        addToDictMap(dict[i], 0, &hashHead);
    }

    char* sentenceItem[1002] = {0};
    char* begin = sentence;
    char* end = sentence;
    int outLen = 0;
    char* result = (char *)malloc(1000002);
    result[0] = '\0';
    int resultLen = strlen(result);

    while (*end != '\0') {
        if (*end == ' ') {
            memset(sentenceItem, 0, 1002);
            strncpy(sentenceItem, begin, (end - begin));
            sentenceItem[end - begin] = '\0';
            outLen = 0;
            getRootChar(sentenceItem, &hashHead, &outLen);
            if (outLen == 0) {
                outLen = strlen(sentenceItem);
            }
            resultLen = strlen(result);
            strncpy(result + resultLen, sentenceItem, outLen);
            result[resultLen + outLen] = ' ';
            result[resultLen + outLen + 1] = '\0';
            end++;
            begin = end;
            continue;
        }
        end++;
    }
    memset(sentenceItem, 0, 1002);
    strncpy(sentenceItem, begin, (end - begin));
    sentenceItem[end - begin] = '\0';
    outLen = 0;
    getRootChar(sentenceItem, &hashHead, &outLen);
    if(outLen == 0) {
        outLen = strlen(sentenceItem);
    }
    resultLen = strlen(result);
    strncpy(result + resultLen, sentenceItem, outLen);
    result[resultLen + outLen] = '\0';

    for (i = 0; i < 26; i++) {
        if (hashHead.map[i] != NULL) {
            freeHash(hashHead.map[i]);
        }
    }
    return result;
}
```