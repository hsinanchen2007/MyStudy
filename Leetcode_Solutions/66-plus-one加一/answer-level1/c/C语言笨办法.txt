### 解题思路
此处撰写解题思路

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize){
    if (digitsSize < 0) {
        return returnSize;
    }
    digits[digitsSize -1] += 1;
    int index = digitsSize - 1;
    int jw = 0;
    while (index >= 0) {
        if(jw == 1) {
           digits[index] += 1; 
           jw = 0;
        } 
        if(digits[index] >= 10) { 
            digits[index] -= 10; 
            jw = 1;
            index--;
        } else {
            jw = 0;
            index--;
        }
    }
    *returnSize = digitsSize; 
    if(jw == 1) {
        int* ret = (int*)malloc(sizeof(int) * (digitsSize + 1));
        ret[0] = 1;
        for (int i = 0; i < digitsSize; i++)
        {
            ret[i + 1] = digits[i];
        }
        *returnSize = digitsSize + 1;
        return ret;
    }
    else {
        return digits;
    }
}
    




```