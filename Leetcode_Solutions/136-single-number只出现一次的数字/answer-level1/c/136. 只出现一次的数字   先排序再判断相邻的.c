int comp(const void*a,const void*b)//用来做比较的函数。
{    
    return *(int*)a-*(int*)b;
}

int singleNumber(int* nums, int numsSize){

    qsort(nums, numsSize, sizeof(int),comp);//调用qsort排序

    int tmp = 0;
    for(int i = 0; i < numsSize-2; i += 2){
        if(nums[i] != nums[i+1]){
            return nums[i];
        }
    }
    return nums[numsSize-1];
}