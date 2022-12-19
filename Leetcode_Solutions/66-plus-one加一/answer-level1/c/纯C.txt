### 解题思路
纯C

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize){
    int index = digitsSize - 1;
    int reverse = 0;
    int temp = 0;
    int carry = 1; // 加一
    int num = 0;
    *returnSize = 0;

    int* pRes = (int*)malloc((digitsSize + 1) * sizeof(int));

    for (index = digitsSize - 1; 0 <= index || carry; index--)
    {
        num = index < 0 ? carry : digits[index] + carry;
        pRes[(*returnSize)++] = num % 10;
        carry = num / 10;
    }   

    for (index = 0, reverse = (*returnSize) - 1; index < reverse; index++, reverse--)
    {
        temp = pRes[index];
        pRes[index] = pRes[reverse];
        pRes[reverse] = temp;
    }

    return pRes;
}
```