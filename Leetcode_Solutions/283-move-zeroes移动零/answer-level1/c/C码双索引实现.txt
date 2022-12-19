### 解题思路
1. 双索引遍历，前索引的值为0时停止，后索引的值非0时进行替换，直到结束。
2. 时间复杂度$O(n)$，空间复杂度$O(1)$。

### 代码

```c
void moveZeroes(int* nums, int numsSize){
    int i, j;
    for (i = 0; j < numsSize;) {
        if (nums[i] == 0) {
            if (nums[j] != 0) {
                nums[i] = nums[j];
                nums[j] = 0;
                i++;
            } else {
                j++;
            }
        } else {
            i++;
            j = i + 1;
        }
    }

    return;
}
```

### 执行结果

执行用时：16 ms, 在所有 C 提交中击败了87.79%的用户
内存消耗：7.5 MB, 在所有 C 提交中击败了100.00%的用户