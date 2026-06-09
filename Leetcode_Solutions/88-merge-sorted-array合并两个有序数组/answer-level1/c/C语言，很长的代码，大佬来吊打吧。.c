### 解题思路
![image.png](https://pic.leetcode-cn.com/2b307291ff6061e1da08881e5f0d38370d9f8a87c7bc53221ce1034aac7e5d07-image.png)

最简单的思路，先新建一个数组。
使用两个指针，从头到尾遍历两个数组。
当其中一个指针达到尾部后，将另外一个数组里的内容附在新建数组的后边。
最后将数据复制到nums1中。
over

### 代码

```c
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    int *output = (int *)malloc(sizeof(int)*(nums1Size+1));
    memset(output, 0, sizeof(int)*(nums1Size+1));

    int i=0,j=0,k=0;
    while(1)
    {
        if(i<m && j<n)
        {
            if(nums1[i] < nums2[j])
            {
                output[k]=nums1[i];
                i++;
                k++;
            }else if(nums1[i]>nums2[j])
            {
                output[k]=nums2[j];
                k++;
                j++;
            }else
            {
                output[k]=nums1[i];
                k++;
                i++;
                output[k]=nums2[j];
                k++;
                j++;
            }
        }
       else if(i==m)
        {
            if(j==n)
            {
                break;
            }
            for(int temp=j;temp<n;temp++)
            {
                output[k]=nums2[temp];
                k++;
            }
            break;
        }
       else if(j==n)
        {
            if(i==m)
                break;
            for(int temp=i;temp<m;temp++)
            {
                output[k]=nums1[temp];
                k++;
            }
            break;
        }
      
    }
    for(int i=0;i<k;i++)
    {
        nums1[i]=output[i];
    }

}
```