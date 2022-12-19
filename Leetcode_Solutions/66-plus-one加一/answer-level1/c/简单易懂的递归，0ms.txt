void change(int* nums,int pos){
    if (nums[pos] == 9) {
        nums[pos]  = 0;
        if(pos > 0) {
            change(nums,pos -1);
        }
    }else {
        nums[pos] ++;
    }
    
}

int* plusOne(int* digits, int digitsSize, int* returnSize){
    
    change(digits,digitsSize-1);
    if (digits[0] != 0){
        *returnSize = digitsSize;
        return digits;
    }else {
        int *result = malloc((digitsSize+1) * sizeof(int));
        memcpy(result+1,digits,digitsSize*sizeof(int));
        result[0] = 1;
        *returnSize = digitsSize +1;
        return result;
    }
}