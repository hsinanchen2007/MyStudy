执行用时 :4 ms, 在所有 C 提交中击败了93.44%的用户
内存消耗 :7 MB, 在所有 C 提交中击败了90.46%的用户
```
if (numsSize == 0) {
        return 0;
    }
    int index = 0;
    for (int i = 1; i < numsSize; i++) {
        if (*(nums+i) != val) {
            index++;
            nums[index] = nums[i];
        }
    }
    return index;
}
```