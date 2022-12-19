```c
int findMaxConsecutiveOnes(int* nums, int numsSize)
{
    int i, t = 0, max = 0;
    for(i = 0; i < numsSize; i++){
        if(nums[i] == 1){
            t++;
        }
        if(nums[i] == 0){
            t = 0;
        }
        max = fmax(max, t);
    }
    return max;
}   
```