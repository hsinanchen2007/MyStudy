
```
#define MIN_NUM(a, b)  ((a) < (b) ? (a) : (b))
#define MAX_NUM(a, b)  ((a) > (b) ? (a) : (b))

int movesToMakeZigzag(int* nums, int numsSize)
{
    int min1 = 0; 
    int min2 = 0;
    
    if (numsSize <= 2) {
        return 0;
    }
    
    /* 奇数索引数大的情况 ，减偶数索引的数*/
    for (int i = 1; i < numsSize - 1; i += 2) {
        min1 += MAX_NUM(0, (nums[i] - MIN_NUM(nums[i - 1], nums[i + 1]) + 1));
    }
    
    if (numsSize % 2 == 0) { /* 算最后一个数 */
        min1 += MAX_NUM(0, (nums[numsSize - 1] - nums[numsSize - 2] + 1));
    }

    /* 偶数索引数大的情况 ，减奇数索引的数*/
    for (int i = 2; i < numsSize - 1; i += 2) {
        min2 += MAX_NUM(0, (nums[i] - MIN_NUM(nums[i - 1], nums[i + 1]) + 1));
    }
    
    if (numsSize % 2 == 1) { /* 算最后一个数 */
        min2 += MAX_NUM(0, (nums[numsSize - 1] - nums[numsSize - 2] + 1));
    }
    
    /* 减奇数的情况要考虑第1个元素 */
    min2 += MAX_NUM(0, (nums[0] - nums[1] + 1));
    
    return MIN_NUM(min1, min2);
}
```