### 解题思路
双指针，移动时候注意消减左边的数字

### 代码

```c

int minSubArrayLen(int s, int* nums, int numsSize){
    int i;
    int j = 0;
    int sumNum = 0;
    int finFlag = 0;
    int minSum;
    for (i = 0; i < numsSize; i++) {
        sumNum = nums[i] + sumNum;
        if (sumNum >= s) {
            /*消减*/
            minSum = sumNum - nums[j];
            while (minSum >= s) {
                sumNum = sumNum - nums[j];
                j++;
                minSum = minSum - nums[j];
            }
            if(finFlag == 0) {
                finFlag = i - j + 1;
            } else {
                finFlag = finFlag >= (i - j + 1) ? (i - j + 1) : finFlag;
            }
            if (finFlag == 1) return 1;
        }
    }
    return finFlag;
}
另一种方法：想象成一个滑动窗口，非常耗时
int minSubArrayLen(int s, int* nums, int numsSize){
    int i;
    int j = 0;
    int sumNum = 0;
    int finFlag = 0;
    for (i = 0; i < numsSize;) {
        sumNum = nums[i] + sumNum;
        if (sumNum >= s) {
            if(finFlag == 0) {
                finFlag = i - j + 1;
            } else {
                finFlag = finFlag >= (i - j + 1) ? (i - j + 1) : finFlag;
            }
            if (finFlag == 1) return 1;
            sumNum = 0;
            j++;
            i = j;  
        } else {
            i++;
        }
    }
    return finFlag;
}