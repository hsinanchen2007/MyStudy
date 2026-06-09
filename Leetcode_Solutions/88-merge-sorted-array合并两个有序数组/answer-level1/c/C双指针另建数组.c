### 解题思路
另建一个长m+n的数组，双指针分别指向两数组，逐步放入相对小值

记得处理两个数组其中一个为0的情况，双指针默认至少都有一个元素了，一定切记特殊情况 0下标也无值的情况....

### 代码

```c
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){

    if(n==0) 
    {
        return 0;
    }
    else if(m==0) 
    {
        for(int i=0;i<n;i++)
        {
            nums1[i] = nums2[i];
        }
        return 0;
    }
    
    
    
    
    
    
    int p=0;
    int q=0;
    int sum = m+n;
    int num[sum];
    for(int i=0;i<sum;i++)
    {
        num[i]=0;
    }
    int i=0;
    while(true)
    {
        if(nums1[p]<=nums2[q])
        {
            num[i++] = nums1[p++];
            
            if(p==m) break;
        }
        else
        {
            num[i++] = nums2[q++];
            
            if(q==n) break;
        }
    
    }

    if(p==m)
    {
        for(int j=i;j<m+n;j++)
        {
            num[j] = nums2[q++];
        }
    }

    else if(q==n)
    {
        for(int j=i;j<m+n;j++)
        {
            num[j] = nums1[p++];
        }
    }



    for(int j=0;j<sum;j++)
    {
        nums1[j]=num[j];
    }
}
```