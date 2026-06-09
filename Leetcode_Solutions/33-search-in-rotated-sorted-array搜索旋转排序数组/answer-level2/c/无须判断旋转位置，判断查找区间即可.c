### 解题思路
数组经过旋转，肯定是分段升序排序，只需要判断target位于前部分还是后部分。target比较0位和末尾的值，如果target < 末尾 && target < 0位，则说明target肯定在后半段升序中。查找过程中，如果出现 i+1 的值 > i，则认为到了反转位置，不需要继续查找，缩短了查找范围。

### 代码

```c
int search(int* nums, int numsSize, int target){
    if (numsSize == 0) {
        return -1;
    }

    if (target <= *(nums + numsSize - 1) && target < *nums) {
        for (int n = numsSize - 1; n >= 0; n--) {
            if (target == *(nums + n)) {
                return n;
            }

            if (n < (numsSize - 1) && *(nums + n) > *(nums + n + 1)) {
                break;
            }
        }
    }
    else {
        for (int n = 0; n < numsSize; n++) {
            if (target == *(nums + n)) {
                return n;
            }

            if (n >= 1 && *(nums + n) < *(nums + n - 1)) {
                break;
            }
        }
    }

    return -1;
}
```