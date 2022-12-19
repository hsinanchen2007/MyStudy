### 解题思路
1. 先遍历一次数据，计算返回的长度len。
2. 使用双索引，从后向前填充，直接填完len个数据停止。
3. 时间复杂度为$O(n)$，空间复杂度为$O(1)$。

### 代码

```c
int removeElement(int* nums, int numsSize, int val){
    int i, j;
    int len = 0;

    for (i = 0; i < numsSize; i++) {
        if (nums[i] != val) {
            len++;
        }
    }

    for (i = 0, j = numsSize - 1; i < len;) {
        if (nums[i] == val) {
            if (nums[j] != val) {
                nums[i] = nums[j];
                i++;
                j--;
            }
            else {
                j--;
            }
        } else {
            i++;
        }
    }

    return len;
}
```

### 执行结果
执行用时 :4 ms, 在所有 C 提交中击败了79.91%的用户
内存消耗 :5.6 MB, 在所有 C 提交中击败了100.00%的用户