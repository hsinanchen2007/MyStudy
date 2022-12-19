没有好好看题，然后duangduangduanga帅气地敲完异或解法，哇，AC，结果，阿偶，有时间复杂度要求，异或是O(n)


言归正传，说一下二分查找的**解题思路**：
1. 我们假设那个单独的数下标为index，然后就会发现，当m为偶数时候，mid+1<index的话，满足nums[m]==nums[m+1],也就是说单独的数前面的一堆数都成双成对。也即，index在[m+2,h]
2. 我们使m一直为偶数，即使算出来为奇数也把它前移一位（mid--）
3. 然后index后面的数，因为这个单独的数插足，后面本来下标为偶数的都与其后一位成双成对，现在全乱了，反应出来就是nums[m]!=nums[m+1]，也即index在[l,m]
4. 根据以上我们就分析出来了在什么条件下，l，h该怎么移动

# 二分法，O(logn)
```
int singleNonDuplicate(int* nums, int numsSize){
    int l=0,h=numsSize-1,m;
    while(l<h){
        m=l+(h-l)/2;
        if(m%2==1)
            m--;
        if(nums[m]==nums[m+1])
            l=m+2;
        else
            h=m;
    }
    return nums[l];
}
```
# 异或法,O(n)
```
int singleNonDuplicate(int* nums, int numsSize){//感觉是用异或，成双成对
    int temp=nums[0],i;
    for(i=1;i<numsSize;i++){
        temp=temp^nums[i];
    }
    return temp;
}
```

