# 按照左括号的奇偶分组
```
int* maxDepthAfterSplit(char * seq, int* returnSize){
    int len = strlen(seq);
    *returnSize = len;
    int *answer = (int *)malloc(len * sizeof(int));
    memset(answer, 0, len * sizeof(int));
    int left = 0;
    for (int i = 0; i < len; i++) {
        if (seq[i] == '(') {
            answer[i] = left % 2;
            left++;
        }else {
            left--;
            answer[i] = left % 2;
        }
    }
    return answer;
}
```
