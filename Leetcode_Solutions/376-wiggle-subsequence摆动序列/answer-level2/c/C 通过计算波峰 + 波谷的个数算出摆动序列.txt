
摆动序列实际就是波峰和波谷的个数

```
int wiggleMaxLength(int* nums, int numsSize)
{
    int preOffSet = 0; 
    int count = 1;
    int curOffSet = 0;

    if (nums == NULL || numsSize == 0)  {
        return 0;
    }

    for (int i = 1; i < numsSize; i++) {
        curOffSet = nums[i] - nums[i - 1];
        if (curOffSet == 0) {
            continue;
        }

        if (preOffSet == 0) {
            preOffSet = curOffSet;
            count++;
            continue;
        }

        if (curOffSet * preOffSet < 0) { // 找到切换点
            count++;
        }

        preOffSet = curOffSet;
    }
    
    return count;
}
```
