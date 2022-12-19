### 解题思路
执行用时 :2784 ms, 在所有 C 提交中击败了7.64%的用户
内存消耗 :8.8 MB, 在所有 C 提交中击败了97.92%的用户 
用时爆炸。。。
先快排，再找数

### 代码

```c
/*
void prt(int *a,int s,int e)
{
    printf("\n%d %d\n",s,e);
    for(int i=s;i<=e;i++)
    {
        printf("%d ",a[i]);
    }
    
}
*/
void quicksort(int *a,int start,int end)
{
   // prt(a,start,end);
    if(start<end)
    {
        int l,r;
        l=start;
        r=end-1;

        while(l<r)
        {
            while(l<r && a[end]>a[l])
            {
                l++;
            }
            while(l<r && a[end]<=a[r])
            {
                r--;
            }
            if(l<r)
            {
                int t=a[l];
                a[l]=a[r];
                a[r]=t;
                l++;
                r--;
            }            
        }
        if(a[l]>a[end])
        {
            int t=a[l];
            a[l]=a[end];
            a[end]=t;
        }
        if(l>0)
        {
            quicksort(a,start,l);
        }
        quicksort(a,l+1,end);
    }
}

int majorityElement(int* nums, int numsSize){
    if(numsSize==1)
    {
        return nums[0];
    }
    quicksort(nums,0,numsSize-1);
    int n=nums[0];
    int cnt=1;
    for(int i=1;i<numsSize;i++)
    {
       // printf("%d ",nums[i]);
        if(n==nums[i])
        {
            cnt++;
            if(cnt>numsSize/2)
            {
                return nums[i];
            }
        }
        else
        {
            cnt=1;
            n=nums[i];
        }
    }
    return 0;
}
```