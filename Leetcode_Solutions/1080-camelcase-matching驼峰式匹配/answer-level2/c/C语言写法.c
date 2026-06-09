```
bool isMatch(char* queries, char* pattern) 
{
    int qLen = strlen(queries);
    int pLen = strlen(pattern);
    int index1 = 0;
    int index2 = 0;
    char ch = 0;

    while (index1 < qLen && index2 < pLen) {
        // 如果两个都相等的话，那么都往后移动
        ch = queries[index1];
        if (ch == pattern[index2]) {
            index1++;
            index2++;
        } else if (ch >= 'a' && ch <= 'z') { // 如果出现了不匹配的小写字符
            index1++;
            continue;
        } else if (ch >= 'A' && ch <= 'Z') { // 如果出现了不匹配的大写字符
            printf("false1\n");
            return false;
        }
    }

    printf("index1 = %d\n", index1);
    printf("index2 = %d\n", index2);
    if (index2 < pLen) {
        printf("false2\n");
        return false;
    }

    while (index1 < qLen) {
        ch = queries[index1];
        if (ch >= 'A' && ch <= 'Z') { // 如果出现了不匹配的大写字符
            printf("false3\n");
            return false;
        }
        index1++;
    }

    printf("true\n");
    return true;
}


bool* camelMatch(char ** queries, int queriesSize, char * pattern, int* returnSize)
{
    bool* ret = (bool*)malloc(sizeof(bool) * (queriesSize + 1));
    memset(ret, 0, sizeof(bool) * (queriesSize + 1));

    int retIndex = 0;
    int i = 0;
    for (i = 0; i < queriesSize; i++) {
        printf("=========================\n");
        if (isMatch(queries[i], pattern)) {
            printf("1\n");
            ret[retIndex] = true;
        } 
        retIndex++;
    }
    
    printf("retIndex = %d\n", retIndex);
    *returnSize = retIndex;
    return ret;
}
```
