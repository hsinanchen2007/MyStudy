### 解题思路
此处撰写解题思路

### 代码

```c
int findMaxConsecutiveOnes(int* nums, int numsSize){
    int max = 0;
    int cnt = 0;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == 0) {
            if (cnt > max) {
                max = cnt;
            }
            cnt = 0;
        }
        else {
            cnt++;
        }
    }

    if (cnt > max) {
        max = cnt;
    }

    return max;
}
```