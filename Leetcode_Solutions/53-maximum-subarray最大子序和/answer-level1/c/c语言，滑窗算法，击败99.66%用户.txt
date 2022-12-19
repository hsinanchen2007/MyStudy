### 解题思路
1.首先判断是否都是负数，如果都是负数，找到其中最大的输出；
2.如果有正数，将这个正数记做start,end不断向后移动，计算累计之和，如果累计之和大于max，则记录下这个和，如果小于0，则将start跳到end处继续计算。
时间复杂度只有O(n)

### 代码

```c
int maxSubArray(int* nums, int numsSize){
    int i;
    int isAllMinus = 1;
    int maxNum = -100000000;
    int start, end;
    int sum = 0;

    if (numsSize == 0) {
        return 0;
    }
    if (numsSize == 1) {
        return nums[0];
    }
    for (i = 0; i < numsSize; i++) {
        if (nums[i] > 0) {
            isAllMinus = 0;
            break;
        }
    }

    if (isAllMinus == 1) {
        for (i = 0; i < numsSize; i++) {
            maxNum = (maxNum > nums[i]) ? maxNum : nums[i];
        }
        return maxNum;
    }

    for (i = 0; i < numsSize; i++) {
        if (nums[i] > 0) {
            start = i;
            break;
        }
    }
    printf("start = %d", start);
    if (numsSize - 1 == start) {
        printf("a");
        return nums[start];
    }
    
    end = start;
    sum = 0;
    while (end < numsSize) {
        sum += nums[end];
        if (sum > maxNum) {
            printf("%d", sum);
            maxNum = sum;
        } else if (sum <= 0) {
            start = end;
            sum = 0;
        }
        end++;
    }
    return maxNum;
}


```