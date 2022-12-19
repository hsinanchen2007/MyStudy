//由于是排好序的数组，可以采用快慢指针算法。
//比对慢指针i的值和快指针j的值，如果不一样，那么慢指针的下一个位置存储快指针的值
int removeDuplicates(int* nums, int numsSize){
    int i,j;
    if(numsSize == 0)
        return numsSize;
    for(i=0,j=1;j<numsSize;j++){
        if(nums[i]!=nums[j])
            nums[++i]=nums[j];
    }
    return numsSize = i+1;
}