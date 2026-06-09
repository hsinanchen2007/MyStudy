```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* maxDepthAfterSplit(char * seq, int* returnSize){
    if (seq == NULL) {
        *returnSize = 0;
        return NULL;
    }
    int index;
    int len = strlen(seq);
    int leftCount = 0;
    int* ret = (int*)malloc(sizeof(int) *  len);
    *returnSize = len;
    int* p = ret;
    while (*seq) {
        if (*seq == '(') {
            ++leftCount;
            *p = leftCount & 1;
        } else {
            *p = leftCount & 1;
            --leftCount;
        }

        ++seq;
        ++p;
    }
    return ret;
}


```