把所有数字累加得到sum
求sum%3是1还是2
分别找出数组中最小的两个%3得1的数字和两个%3得2得数字
再进行判断相减
```
int cmp(const void* a ,const void* b){
    return *(int*)a>*(int*)b;
}
int maxSumDivThree(int* nums, int numsSize){
    int sum=0;
    int a[100000],b[100000],m=0,n=0;
    for(int i=0;i<numsSize;i++){
            sum+=nums[i];
        if(nums[i]%3==1)
            a[n++]=nums[i];
        if(nums[i]%3==2)
            b[m++]=nums[i];
    }
    if(sum%3==0)
        return sum;
    qsort(a,n,sizeof(int),cmp);
    qsort(b,m,sizeof(int),cmp);
    if(sum%3==1){
        if(n&&m>1)
            return sum-a[0]>sum-b[0]-b[1]?sum-a[0]:sum-b[0]-b[1];
        if(n)
            return sum-a[0];
        return sum-b[0]-b[1];
    }
    if(n>1&&m)
            return sum-a[0]-a[1]>sum-b[0]?sum-a[0]-a[1]:sum-b[0];
    if(m)
            return sum-b[0];
    return sum-a[0]-a[1];
}
```
