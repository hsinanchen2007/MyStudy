![image.png](https://pic.leetcode-cn.com/636fc7de866c1bf94f920a53028d8fc810f76f8d6aa7a1bc227df4b89166a3d8-image.png)

利用旋转数组原本为递增数组的特性使用二分法：

int findMin(int* nums, int numsSize){
    int start=0,end=numsSize-1,mid,i;
    
    if(nums==NULL || numsSize<=0)
    return -1;
    /* 数组只有一个元素 */
    if(numsSize==1)
    return nums[0];
    /* 数组为递增数组，即将0个元素搬到数组末尾 */
    if(nums[start]<nums[end])
    return nums[start];
    do{
        mid=(start+end)/2;
        /* nums[start]==nums[mid]==num[end]：无法确定最小值在哪个区间，从两头朝中间缩减区间*/
        if(nums[start]==nums[end] && nums[start]==nums[mid]){
            if(nums[start]>nums[start+1])
            return nums[start+1];
            else if(nums[end]<nums[end-1])
            return nums[end];
            else{
                start++;
                end--;
            }
        }
        else if(nums[mid]>=nums[start]){
            start=mid;
        }
        else if(nums[mid]<=nums[end]){
            end=mid;
        }
    }while(end-start>1);
    return nums[end];
}

