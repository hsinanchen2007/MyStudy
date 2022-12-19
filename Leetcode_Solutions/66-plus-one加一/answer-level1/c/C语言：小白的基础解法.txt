```
从末端元素开始，连续的9都变为0，非9加一后退出循环，然后分首位是否进位两种情况。
int* plusOne(int* digits, int digitsSize, int* returnSize){
    int *num = (int*)malloc(sizeof(int) * (digitsSize + 1));
    num[0] = 1;
    int i;
    for (i = digitsSize - 1; i >= 0; i--){
        if (digits[i] == 9)
            digits[i] = 0;
        else{
            digits[i] += 1;
            break;
        }
    }
    *returnSize = (digits[0] == 0) ? (digitsSize + 1) : digitsSize;
    for (i = 0; i < digitsSize; i++){
        num[i + 1] = digits[i];
    }
    return (digits[0] == 0) ? num : digits;       
}
```
