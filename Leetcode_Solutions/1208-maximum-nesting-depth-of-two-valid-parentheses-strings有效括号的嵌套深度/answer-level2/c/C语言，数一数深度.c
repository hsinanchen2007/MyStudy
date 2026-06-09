### 解题思路
我承认，我是看了官方题解后，用c语言实现了一下 ：） 关键是理解题目意思，嗯哼

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* maxDepthAfterSplit(char * seq, int* returnSize){
    if(seq == NULL) {
        *returnSize = 0;
        return NULL;
    }
    if(strlen(seq) == 0) {
        *returnSize = 0;
        return NULL;
    }
    int* ret = malloc(sizeof(int)*strlen(seq));
    int d = 0;
    for(int i=0; i<strlen(seq); i++) {
        if(seq[i] == '(') {
            d++;
            ret[i] = d % 2;
        } else {
            ret[i] = d % 2;
            d--;
        }
    }
    *returnSize = strlen(seq);
    return ret;
}
```