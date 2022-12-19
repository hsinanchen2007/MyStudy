```


void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
    int *p = nums1;         // p指针 遍历num1数组
    int *q = nums2;         // 移动q指针进行比较
    int i = 0;          // 计p的移动
    int k = 1;          // 用于num2的进位
    int x;
    while( m < nums1Size )
    {
        if( *p <= *q )
        {
            if( i == m )        // 当 i = m 时 p已经移动到nums1存放元素的后一位 
            {
                 for( x = m; x > i; x-- )
                    *(nums1 + x) = *(nums1 + x - 1);        // 将待插入元素后的元素全部往后移一位
                 *(nums1 + i) = *q;
                 m++;                                       // num1s数组存放的数据加1
                 q = (nums2 + k);                           // 将q指向下一位
                 k++;
            }
            else
            {
                i++;
                p = (nums1 + i);
            }
        }
        else
        {
            for( x = m; x > i; x-- )
                *(nums1 + x) = *(nums1 + x - 1);
            *(nums1 + i) = *q;
            m++;
            q = (nums2 + k);
            k++;
        }
    }
}

```
