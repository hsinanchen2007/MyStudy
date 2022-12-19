### 解题思路
1.使用栈的思想，但是本题由于只有左右括号，可以不用真正申请空间，只用个idx就行；
思路：求栈的最深的深度，然后将前一半的保存为1，另一半保存为0就行
1.求本次栈的深度的一半是多深；
2.循环遍历数组，将前一半结果设置成1，后一半设置为0；

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int getHalfDepth(char *seq) {
    char *tmp = seq;
    int top = 0;
    int depmax = 0;
    while (*tmp != '\0') {
        if (*tmp == '(') {
            top++;
            if (depmax < top)
                depmax = top;
        } else {
            top--;
        }
        tmp++;
    }

    return depmax / 2;
}

void setRet(int top, int dep, int idx, int *ret) {
    if (top < dep) 
        ret[idx] = 0;
    else
        ret[idx] = 1;
}

int* maxDepthAfterSplit(char * seq, int* returnSize){
    *returnSize = strlen(seq);
    int *ret = (int *)malloc(sizeof(int) * strlen(seq));
    memset(ret, 0, sizeof(int) * strlen(seq));

    int top = 0;
    int dep = 0;
    int idx = 0;
    char *tmp = seq;

    dep = getHalfDepth(seq);

    while (*tmp != '\0') {
        if (*tmp == '(') {
            setRet(top, dep, idx, ret);
            top++;
        } else {
            top--;
            setRet(top, dep, idx, ret);
        }
        tmp++;
        idx++;
    }

    return ret;
}
```