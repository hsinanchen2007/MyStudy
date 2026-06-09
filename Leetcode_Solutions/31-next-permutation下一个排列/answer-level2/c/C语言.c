/*
从数组最后第二位判断， 到数组结束， 是否时最最大的，如果上最大的， 继续往前遍历
如果不上最大的， 就可以在此位到最后位找到下一个字典数
找到大于这一位的数中最小的数，和此位互换
从这一位的后一位进行生序排序
*/
int comp(const void*a,const void*b)
{
    return *(int*)a-*(int*)b;
}
int checknum(int* nums, int begin, int numsSize)
{
    for (int i = begin; i < numsSize-1; i++) {
        if (nums[begin] < nums[i+1]) {
            return 1;
        }
    }
    return 0;
} 
int findnum(int* nums, int begin, int numsSize)
{
    int ret = begin+1;
    for (int i = begin; i < numsSize-1; i++) {
        if (nums[begin] < nums[i+1]) {
            if (nums[ret] > nums[i+1]) {
                ret = i+1;
            }         
        }
    }
    return ret;
} 
void nextPermutation(int* nums, int numsSize){
    for (int i = numsSize - 2; i >= 0; i-- ){
        if (checknum(nums, i, numsSize) == 1) {
            int bit = findnum(nums, i, numsSize);
            int tmp = nums[i];
            nums[i] = nums[bit];
            nums[bit] = tmp;
            qsort(nums+i+1,numsSize-i-1,sizeof(int),comp);
            return nums;
        }
    }
    qsort(nums, numsSize, sizeof(int), comp);
    return nums;
}

