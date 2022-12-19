思路：
1. 数组有序，且某元素出现次数超过25%
2. 那么对于此元素第1次出现位置，加25%数组长度，必定仍为它自身

```C
int findSpecialInteger(int* arr, int arrSize) {
    for (int *p = arr, *q = arr + arrSize / 4; ; p++, q++)
        if (*p == *q) return *p;
    return 0;  
}
// 执行用时 :8 ms, 在所有 c 提交中击败了100.00%的用户
```
