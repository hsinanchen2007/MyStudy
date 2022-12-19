step1:找到pattern长度，lenth；
step2:遍历query中的一个字符串；query中用i作下标表示当前字符，
step3:依次与pattern中的字符比较，pattern中用j做下标表示当前字符；
step4:query中遍历到大写字符的时候，必须等于pattern中的当前字符；不等则直接break，标记false；
step5:比较j与lenth，不等则表示pattern中还有字符没有在query中出现，标记flase；其他的都已经被标记成true了，不用管；

```
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool* camelMatch(char ** queries, int queriesSize, char * pattern, int* returnSize){
    int lenth, i, j, idx;
    lenth = i = j = 0;
    bool *res = malloc(queriesSize * sizeof(bool));
    res[0] = true;
    while (pattern[lenth] != '\0') {
        lenth++;
    }
    for (idx = 0; idx < queriesSize; idx++) {
        i = j = 0;
        while (queries[idx][i] != '\0') {
            //printf("001  %d %c - %d %c \n",i,queries[idx][i], j, pattern[j]);
            if(queries[idx][i] >= 'Z') {
                if (queries[idx][i] == pattern[j]) {
                    i++;
                    j++;
                    //printf("i++j++\n ");
                } else {
                    //printf("i++\n ");
                    i++;
                }
                //printf("002  %d %c - %d %c \n",i,queries[idx][i], j, pattern[j]);
            } else {
                if (queries[idx][i] == pattern[j]) {
                    i++;
                    j++;
                } else {
                    res[idx] = false;
                    //printf("4444  %d %c - %d %c \n",i,queries[idx][i], j, pattern[j]);
                    break;
                }
                //printf("003  %d %c - %d %c \n",i,queries[idx][i], j, pattern[j]);
            }
            res[idx] = true;
        }
        if (j < lenth) {
            res[idx] = false;
        }
    }
    *returnSize = queriesSize;
    return res;
}
```
