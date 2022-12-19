### 解题思路
此处撰写解题思路

### 代码

```c
//先存map,然后比对
#define MAX_NUM 1000
int cmp(char *key, char *str) {
    int keyLen = strlen(key);
    int strLen = strlen(str);
    if (keyLen > strLen) {
        return 0;
    }
    int index = 0;
    while( index < keyLen && key[index] == str[index]) {
        index++;
    }
    if (index == keyLen) {
        return 1;
    }
    return 0;
}
char *replaceWords(char **dict, int dictSize, char * sentence){
    if (dictSize == 0) {
        return sentence;
    }
    char **mapStat = (char **)malloc(sizeof(char *) * MAX_NUM);
    for (int i = 0; i < MAX_NUM; i++) {
        mapStat[i] = (char *)calloc(MAX_NUM, sizeof(char));
    }
    int strLen = strlen(sentence);
    int lastIndex = -1;
    int mapSize = 0;
    for (int i = 0; i < strLen; i++) {
        if (sentence[i] == ' ') {
            //printf("%d", sizeof(mapStat[mapSize])/sizeof(mapStat[mapSize][0]));
            if (lastIndex  < 0) {
                lastIndex = 0;
                (void)strncpy(mapStat[mapSize], sentence + lastIndex, i - lastIndex);
            } else {
                (void)strncpy(mapStat[mapSize], sentence + lastIndex + 1, i - lastIndex -1);
            }
            lastIndex = i;
            mapSize++;
        }
    }
    //数量整迷糊了
    mapStat[mapSize] = (char *)calloc((strLen - lastIndex + 2), sizeof(char)); // 多申请1个
    (void)strncpy(mapStat[mapSize], sentence + lastIndex + 1, strLen - lastIndex);
    /*-----------存完了-----------*/
    for (int j = 0; j < mapSize + 1; j++) { 
        for (int i = 0; i < dictSize; i++) { // 每次去比较3个字典数据
            /*比较是否相等 进行替换*/
            if (cmp(dict[i], mapStat[j])) {
                memset(mapStat[j], 0, strlen(mapStat[j])); // 清零
                memcpy(mapStat[j], dict[i], strlen(dict[i])); // 拷贝
            }
        }
    }

    int *ret = (int *)calloc((strLen*2), sizeof(char));
    for (int i = 0; i < mapSize; i++) {
        strcat(ret, mapStat[i]);
        strcat(ret, " ");
    }
    
    //printf("%d %d \n",mapSize, strLen);
    //printf("%s", mapStat[mapSize]);
    strcat(ret, mapStat[mapSize]);
    //strcat(ret, mapStat[mapSize]);
    free(mapStat);
    return ret;
}
```