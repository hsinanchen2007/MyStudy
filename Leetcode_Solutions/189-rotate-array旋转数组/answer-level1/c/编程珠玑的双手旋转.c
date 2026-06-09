``` c
/*
* progaming pears
* two hands 
*/
void rotate(int* nums, int numsSize, int k){
    if (k % numsSize == 0) return;
    k %= numsSize;
    
    int i, j, tmp;  
    numsSize--;
    for(i=0,j=numsSize-k; i<=j; i++, j--) {
        tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
 
    for(i=numsSize-k+1,j=numsSize; i<=j; i++, j--) {
        tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
 
    for(i=0, j=numsSize; i<=j; i++,j--) {
       tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
}
```

