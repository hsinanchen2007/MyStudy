基本思想：只需要判断最大元素是否是第二大元素的2倍或者2倍以上即可
具体流程：1.线性找出最大元素，若更新最大元素，那么原最大元素必定为第二大元素，保存
         2.若不更新最大元素，也要同时判断该元素是否大于第二大元素   
```
int dominantIndex(int* nums, int numsSize){
    int i,max=0,maxsec=0,maxi=0;
    for(i=0;i<numsSize;i++)
    {
        if(nums[i]>max)//优先满足第一大元素的判断
        {
            maxsec=max;
            maxi=i;
            max=nums[i];
        }
        else if(nums[i]>maxsec)//其次满足第二大元素的判断
        {
            maxsec=nums[i];
        }
    }
    if(max<2*maxsec)
        return -1;
    return maxi;
}
```
