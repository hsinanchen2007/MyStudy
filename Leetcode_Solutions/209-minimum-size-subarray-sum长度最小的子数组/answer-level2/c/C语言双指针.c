### 解题思路
此处撰写解题思路

### 代码

```c
#define MIN(a, b) (a) < (b) ? (a) : (b)
int minSubArrayLen(int s, int* nums, int numsSize){
    /* 输入有效性判断 */
    if ((s < 1) || (nums == NULL) || (numsSize == 0)) {
        return 0;
    }

    int leftIdx  = 0;
    int rightIdx = 0;
    int sumTmp = 0;
    int minLen = INT_MAX;

    while(rightIdx < numsSize) {
        sumTmp = sumTmp + nums[rightIdx];

        if (sumTmp >= s) {
            minLen = MIN(rightIdx - leftIdx + 1, minLen);
            
            sumTmp = sumTmp - nums[leftIdx];
            leftIdx++;
            while (sumTmp >= s) {
                minLen = MIN(rightIdx - leftIdx + 1, minLen);

                sumTmp = sumTmp - nums[leftIdx];
                leftIdx++;
            }
        }
        rightIdx++;

    }
    if (minLen == INT_MAX) {
        return 0;
    } 
    return minLen;
}
```