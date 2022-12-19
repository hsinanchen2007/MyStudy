```
int jump(int* nums, int numsSize){
    int i;
    int pos;
    int step = 0;

    pos = numsSize - 1;
    while (pos != 0) {//直到POS变成0循环结束
        //从前往后找到第一个可以一步到达POS的
        for (i = 0; i < pos; i++) {  
            if (nums[i] >= pos - i) {
                pos = i;//找到后更新POS
                step++;
                break;
            }
        }
    }
    return step;
}
```
