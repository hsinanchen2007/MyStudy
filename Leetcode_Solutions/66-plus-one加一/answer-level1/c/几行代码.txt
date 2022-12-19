int* plusOne(int* digits, int digitsSize, int* returnSize){

    for(int i = digitsSize -1 ;i>=0;i--){
        if(digits[i]!=9){
            digits[i] = digits[i]+1;
            *returnSize = digitsSize;
            return digits;
        }else
        {
            digits[i] = (digits[i]+1) % 10;
        }
    }
    int *ret = (int *) calloc((digitsSize + 1), (sizeof(int)));
    *returnSize = digitsSize + 1;
    ret[0] = 1;
    return ret;
}