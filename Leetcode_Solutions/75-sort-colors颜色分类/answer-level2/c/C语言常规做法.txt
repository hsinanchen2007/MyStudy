```c
void sortColors(int* nums, int numsSize){
    short red=0,white=0,blue=0,i;
    for(i=0;i<numsSize;i++)
        switch(nums[i]){
            case 0:red++;break;
            case 1:white++;break;
            case 2:blue++;
        }
    for(i=0;i<red;i++) nums[i]=0;
    for(i=red;i<red+white;i++) nums[i]=1;
    for(i=red+white;i<numsSize;i++) nums[i]=2;
}
```