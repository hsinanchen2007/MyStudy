暴力匹配
首先得到最大数的下标
其次按照题目要求进行第二步判断即可
注意for循环边界,防止溢出.

int dominantIndex(int* nums, int numsSize){
    int pos=0;
    int i=0;
    int j=0;
    for(i=1;i<numsSize;i++)
    {
        if(nums[i]>nums[pos])
            pos=i;
    }
     for(i=0;i<numsSize;i++)
    {
        if(i!=pos)
        {
            if(nums[i]*2>nums[pos])
              return -1;  
        }
    }
    return pos;
}
