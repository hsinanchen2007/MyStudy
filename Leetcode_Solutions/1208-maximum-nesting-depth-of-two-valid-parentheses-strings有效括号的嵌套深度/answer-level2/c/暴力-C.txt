### 解题思路
1.这道题不用考虑不符合要求的括号。
2.通核心是过数组进行0和1标记，并使用flag进行交替。
### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* maxDepthAfterSplit(char * seq, int* returnSize){
    int i, j;
    int length;
    int *returnseq;
    int front_flag = 0, end_flag = 0;
    int flag = 1, flag1 = 1;
    if (seq == NULL) {
        return NULL;
    }
    length = strlen(seq);
    returnseq = (int *)malloc(sizeof(int) * (length + 1));
    i = 0;
    j = 0;
    if (seq[i] == ')') {
        return NULL;
    }
    i++;
    returnseq[j++] = 1;
    front_flag++;
    while(seq[i] != '\0') {
        if (flag == 1 && seq[i] == ')') {
            returnseq[j++] = 1;
            flag = 0;
            i++;
            end_flag++;
            continue;
        }
        if (flag == 0 && seq[i] == '(') {
            returnseq[j++] = 1;
            flag = 1;
            i++;
            front_flag++;
            continue;
        }
        if (flag == 1 && seq[i] == '(') {
            returnseq[j++] = 0;
            flag = 0;
            i++;
            front_flag++;
            continue;
        }

        if (flag == 0 && seq[i] == ')') {
            returnseq[j++] = 0;
            flag = 1;
            i++;
            end_flag++;
            continue;
        }
    }
    * returnSize = length;
    return returnseq;
}
```