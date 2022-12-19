### 解题思路
此处撰写解题思路
没有思路
### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool* checkPattren(char *query, char *pattern)
{
    int i = 0;
    int j = 0;

    int pattern_size = 0;
    int query_size = 0;
    while (pattern[pattern_size])
        pattern_size++;

    while (query[query_size])
        query_size++;


    for (i = 0; i < query_size; i++) {
        if ((j < pattern_size) && (pattern[j] == query[i])) {
            j++;
            continue;
        }
        if (query[i] < 'a')
            break;
    }
    if ((j < pattern_size) || (i < query_size))
        return 0;
    else
        return 1;
}

bool* camelMatch(char ** queries, int queriesSize, char * pattern, int* returnSize){
    bool *answer = (bool*)malloc(sizeof(bool) * queriesSize);
    int i;
    for (i = 0; i < queriesSize; i++) {
        answer[i] = checkPattren(queries[i], pattern);
    }
    *returnSize = queriesSize;
    return answer;
}
```