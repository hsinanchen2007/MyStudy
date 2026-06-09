```
int* plusOne(int* digits, int digitsSize, int* returnSize){
    for(int i = digitsSize - 1; i >= 0; --i) {
        //++digits[i];
        digits[i] = ++digits[i] % 10;
        if(digits[i] != 0) {
            int *returnArry = (int*)malloc(digitsSize * sizeof(int));
            memcpy(returnArry, digits, digitsSize * sizeof(int));
            *returnSize = digitsSize;
            return returnArry;
        }
    }
    // such 999
    *returnSize = digitsSize + 1;
    int *returnArry = (int*)malloc(*returnSize * sizeof(int));
    memset(returnArry, 0, *returnSize * sizeof(int));
    returnArry[0] = 1;
    return returnArry;
}
```
