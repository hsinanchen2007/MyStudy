### 解题思路
统计范围内为0的个数，高于1个时移动左窗口

### 代码

```c
int findMaxConsecutiveOnes(int* nums, int numsSize){
    /* 双指针滑动窗口解法 */
    int start = 0;
    int end = 0;
    int ret = INT_MIN;
    bool flag = false;
    int count = 0;

    /* 统计区域内0的个数 */
    while (end < numsSize) {
        if (nums[end] == 0) {
            count++;
        }
        if (ret < end - start) {
            ret = end - start;
        }
        /* 范围内个数大于2 滑动左窗口 */
        if (count > 1) {
            while(start <= end) {
                if (nums[start] == 0) {
                    count--;
                    start++;
                } else {
                    start++;
                }
                if (count <= 1) {
                    break;
                }
            }
        }
        end++;
    }
    if (ret < end - start) {
        ret = end - start;
    }
    return ret;
}
```