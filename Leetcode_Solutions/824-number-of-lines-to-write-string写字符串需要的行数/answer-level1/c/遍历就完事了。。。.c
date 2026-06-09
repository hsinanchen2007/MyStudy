```
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* numberOfLines(int* widths, int widthsSize, char * S, int* returnSize){
    int *res = malloc(sizeof(int) * 2);
    memset(res, 0, sizeof(int) * 2);
    *returnSize = 2;
    int length = strlen(S);
    if(length != 0) {
        res[0] = 1;
    }
    for(int i = 0; i < length; i++) {
        res[1] += widths[S[i] - 'a'];
        if(res[1] > 100) {
            res[1] = 0;
            res[1] += widths[S[i] - 'a'];
            res[0]++;
        }
    }
    return res;
}
```
