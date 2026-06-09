从后向前(从个位)开始+1,逢九进一,不为九时结束,全为九时数组长度加一
解法如下: 特别要注意的是returnSize,这个代表返回指针的长度,要不上层代码不知道要取多少个


```c
int *plusOne(int *digits, int digitsSize, int *returnSize) {

    for (int i = digitsSize - 1; i >= 0; --i) {
        if (digits[i] == 9) {
            digits[i] = 0;
        } else {
            digits[i]++;
            *returnSize = digitsSize;
            return digits;
        }
    }
    int *result = (int *) malloc(sizeof(int) * (digitsSize + 1));
    memset(result, 0, (digitsSize + 1) * sizeof(int));
    result[0] = 1;
    *returnSize = digitsSize + 1;
    return result;
}
```
