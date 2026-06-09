直接根据题目的要求去遍历数组
```
bool circularArrayLoop(int *nums, int numsSize)
{
    if (nums == NULL || numsSize < 2) {
        return false;
    }
    int  *tmpInt = (int *)malloc(numsSize*sizeof(int));
    int   flag   = 0;
    memset(tmpInt, 0, numsSize*sizeof(int));
    for (int i = 0; i != numsSize; i++) {
        flag++;
        int nextPos = i;
        int curPos  = i;
        do {
            curPos  = nextPos;
            if (tmpInt[curPos] == flag) {
                break;
            }
            tmpInt[curPos] = flag;
            nextPos      = nextPos + nums[nextPos];
            while (nextPos >= numsSize) {
                nextPos -= numsSize;
            }
            while (nextPos < 0) {
                nextPos += numsSize;
            }
            if (curPos == nextPos) { // 排除长度为1的情况
                break;
            }
            if ((nums[curPos] >> 31) != (nums[nextPos] >> 31)) { //符号不相等,意味着方向会不同
                break;
            }
            if (i == nextPos) {
                free(tmpInt);
                return true;
            }
        } while (true);
    }
    free(tmpInt);
    return false;
}
```
