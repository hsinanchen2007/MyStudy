### 解题思路
此处撰写解题思路
不需要进位就直接对原数组操作 返回原数组。需要的话就也只是进1，所以最前面加上1即可

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize){
    int carry = 1;
    int i;
    for (i = digitsSize - 1; i >= 0; i--) {
        int sum;
        sum =digits[i] + carry;
        carry = sum / 10;
        digits[i] = sum % 10;
    }
    if (carry) {
        *returnSize = digitsSize + 1;
        int *ret = (int*)malloc(sizeof(int) * (*returnSize));
        int j = 0;
        int k = 1;
        ret[0] = 1;
        for (; j < digitsSize; j++, k++) {
            ret[k] = digits[j];
        }
        return ret;
    }
    *returnSize = digitsSize;
    return digits;
}
```