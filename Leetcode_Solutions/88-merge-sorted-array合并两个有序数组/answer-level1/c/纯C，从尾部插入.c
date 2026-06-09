### 解题思路
从nums1的n+m-1位置开始插入

### 代码

```c
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{//从尾部开始写数据
    int r=m+n-1;//插入数据的尾指针
    int r1=m-1;
    int r2=n-1;

    while(r1>=0&&r2>=0)
    {
        if(nums1[r1]>nums2[r2])
        {
            nums1[r]=nums1[r1];
            --r;
            --r1;
        }
        else
        {
            nums1[r]=nums2[r2];
            --r;
            --r2;
        }
    }

    while(r2>=0)
        nums1[r--]=nums2[r2--];

}
```