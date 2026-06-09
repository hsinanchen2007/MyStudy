
int cmpfunc(const void * a, const void * b)
{
   return ( *(int*)a > *(int*)b );
}

int firstMissingPositive(int* nums, int numsSize){
    
    int i, k=0;
    if(nums == NULL || numsSize<1)
        return 1;

    qsort(nums, numsSize, sizeof(int), cmpfunc);
    
    for(i=0; i< numsSize; i++){
        if(nums[i]<=0){
            continue;
        }
        k++;
        if(nums[i] < k){ //重复数
            k--;
            continue;
        }
        else if(nums[i] > k)
        {
            break;
        }
    }

    if(i == numsSize){
        k++;
    }
    return k;
}