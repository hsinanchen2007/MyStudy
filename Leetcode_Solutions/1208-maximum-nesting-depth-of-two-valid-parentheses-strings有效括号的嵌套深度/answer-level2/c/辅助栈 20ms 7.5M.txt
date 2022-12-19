```
int* maxDepthAfterSplit(char * seq, int* returnSize){
    int len = strlen(seq);
    int top = -1; //辅助栈
    int *res = (int *)malloc(len * sizeof(int));
    for (int i = 0; i < len; i++) {
        if (seq[i] == '(') {
            ++top;
            res[i] = top % 2;
        } else {
            res[i] = top % 2;
            --top;
        }
    }
    *returnSize = len;
    return res;
}
```
