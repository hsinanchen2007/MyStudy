```c
void moveZeroes(int* nums, int numsSize){
    short i,j;
    for(i=0;i<numsSize;i++){
        if(nums[i]==0){
            for(j=i;j<numsSize-1;j++)
                nums[j]=nums[j+1];
            nums[j]=0;
        }
        for(j=i;j<numsSize;j++)
            if(nums[j]!=0) break;
        if(nums[i]==0&&j!=numsSize) i--;
    }
}
```