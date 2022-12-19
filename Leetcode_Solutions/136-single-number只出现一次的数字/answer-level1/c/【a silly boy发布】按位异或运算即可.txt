```
int singleNumber(int* nums, int numsSize){
    if ((nums == NULL) || (numsSize == 0)) {
        return 0;
    }
    if (numsSize == 1) {
        return nums[0];
    }
    
    int returnValue = 0;
    int i;
    for (i = 0; i < numsSize; i++) {
        returnValue = returnValue ^ nums[i];
        //printf("returnValue[%u]: %u\n", i, returnValue);
    }
    
    return returnValue;
}
```
