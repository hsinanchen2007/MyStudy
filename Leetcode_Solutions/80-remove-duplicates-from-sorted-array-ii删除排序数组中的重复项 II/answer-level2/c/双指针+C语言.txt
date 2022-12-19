### 解题思路
双指针思想，l每次在一个数字的第一位，r在下个数字的第一位，r-l就是一个数字出现的次数，如果次数大于二，则用rr来修改数组，然后相应改变数组的总长度s。代码简单易懂。

### 代码

```c
int removeDuplicates(int* nums, int numsSize){
    int s=numsSize;
    int l=0,r=0,rr=0,n=0;
    while(l<s)
    {
        while(r!=s&&nums[l]==nums[r])
        {
            r++;
        }
        n=r-l-2;
        if(n>0)
        {
            rr=r;
            r=l+2;
            while(rr<s)
            {
                nums[rr-n]=nums[rr];
                rr++;
            }
            s-=n;
        }
        l=r;
    }
    return s;
}
```