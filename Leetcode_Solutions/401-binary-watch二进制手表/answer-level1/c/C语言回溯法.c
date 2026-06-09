### 解题思路
用一个长度为10的整型数组存储灯的状态，不亮为0，亮为1。
点亮一个灯后的数组状态成为一个解空间树的节点，在此基础上再进行遍历点灯，灯如果点完则回溯到该节点的父节点，
点下一个位置的灯，以此类推，直到点完

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define MAX_TIME_LEN 10
#define MAX_ARR_LEN 5000
// 将整型数组转化为对应的数字
int getNum(int *numArr, int start, int end)
{
    int i;
    int ans = 0;
    for (i = end - 1; i >= start; i--) {
        if (numArr[i] == 1) {
            // 所在位数的指数为 (end - start) - (i - start) - 1， 整理得：end - i -1
            ans += pow(2, end - i -1);
        }
    }
    return ans;
}
// 回溯算法
void fillArr(int num, char **retArr, int *count, int *timeArr, int index)
{
    int i;
    // 算法结束条件，num为0说明灯已经填充完
    if(num == 0) {
        retArr[(*count)] = (char *)malloc(sizeof(char) * MAX_TIME_LEN);
        sprintf(retArr[(*count)++], "%d:%02d", getNum(timeArr, 0, 4), getNum(timeArr, 4, 10));
        return;
    }
    // 依次点灯
    for (i = index; i < 10; i++) {
        // 只点亮灭的灯
        if (timeArr[i] == 0) {
            timeArr[i] = 1;
            // 要判断是不是超出了时间范围
            if (getNum(timeArr, 0, 4) < 12 && getNum(timeArr, 4, 10) < 60) {
                // 没超出的话进去点下一个灯
                fillArr(num - 1, retArr, count, timeArr, i + 1);
            }
            // 该分支走完后要将这个灯灭掉以便回溯，这是体现回溯的重点
            timeArr[i] = 0;
        }
    }
    return;
}
char ** readBinaryWatch(int num, int* returnSize){
    char **retArr = (char **)malloc(sizeof(char *) * MAX_ARR_LEN);
    int timeArr[MAX_TIME_LEN] = {0};
    int count = 0;
    fillArr(num, retArr, &count, timeArr, 0);
    *returnSize = count;
    return retArr;
}
```