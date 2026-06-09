### 解题思路
判断是否为9
连续为9位需要进位
数字多一位的条件只有两虚的9:9->10,99->100,999->1000.
最后判断最高位是否为0，是则进位

时间复杂度为O(N)，最多O(2N)
空间复杂度为O(N+1)
### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize){
    int *num = (int*)malloc((digitsSize + 1) * sizeof(int));
    num[0] = 1;
    *returnSize = digitsSize;
    for(int i = digitsSize - 1; i >= 0; i--){
        if(digits[i] == 9){
            digits[i] = 0;
        }
        else{
            digits[i]++;
            break;
        }
    }
    if(digits[0] == 0){
        for(int i = 0; i < digitsSize; i++){
            num[i + 1] = digits[i];
        }
        * returnSize = digitsSize + 1;
        return num;
    }
    else
        return digits;
}
```