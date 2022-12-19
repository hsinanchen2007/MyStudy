# 最快 4 毫秒，超过100%，慢的时候也可以十几毫秒说不准
# 一次二分法看起来写的挺舒服的，但其实判断条件十分复杂，仔细想想可能分两次二分说不定更快呢
```


bool search(int* nums, int numsSize, int target){
    if(numsSize<=0||(numsSize==1&&nums[0]!=target))
        return false;
    
    int l=0,h=numsSize-1,m;
    while(l<=h)
    {
        m=(l+h)/2;
        if(nums[m]==target)
            return true;
        
        if(nums[m]==nums[l]&&nums[m]==nums[h])/***中间与两边相等时舍弃两边***/
        {
            l++;
            h--;
        }
        else if(target>nums[m])
        {
            if(nums[m]<=nums[h]&&target>nums[h])
                h=m-1;
            else l=m+1;
        }
        else if(target<nums[m])
        {
            if(nums[m]>=nums[l]&&target<nums[l])
                l=m+1;
            else h=m-1;
        }
    }
    
    return false;
}


```
