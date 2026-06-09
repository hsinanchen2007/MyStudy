### 解题思路
此处撰写解题思路
   /*1、如果总数之和是偶数，则需要在两个数组中从小到大找到第n/2 , n/2 + 1位，例如总共4位，则需要找到第2个，第3个，即n/2 = 2, n/2 + 1 = 3,第2个和第3个数的和，再除以2.
   2、如果总数之和是奇数，则需要在两个数组中从小到大找到第（n + 1）/2位，例如总共5位，则需要找到第（5 + 1）/2 = 3位。
   3、下一步就是排序两个数组，只最多只需要找到num/2 + 1位数，那么根据总数奇偶，就可以知道最后的数就是我们要找的了。
  */
### 代码

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    double result = 0;

    int num = nums1Size + nums2Size;
    int sorted[num];
    int i = 0;
    int j = 0;
    int k = 0;
    /*证明有偶数个*/
    while (i < (num/2 + 1))
    {
        //到两个数组都没排序完时，则需要从两个数组中 获取还没排序的最小，因为题目原始就是两个有序列表
        if ((j < nums1Size) && (k < nums2Size))
        {
            //如果数组1 的数小，则数组1的下表后滑
            if (nums1[j] < nums2[k])
            {
                sorted[i] = nums1[j];
                j ++;
            }
            else
            {
                sorted[i] = nums2[k];
                k++;
            }
        }
        /*如果只剩下一个数组，则只需要这个数组的数*/
        else if (j >= nums1Size)
        {
            sorted[i] = nums2[k];
            k ++;
        }
        else
        {
            sorted[i] = nums1[j];
            j ++;
        }
        i ++;
    }
    if (0 == num%2)
    {
        return ((double)sorted[i-1] + (double)sorted[i-2])/2;
    }
    else
    {
        return sorted[i-1];
    }
}
```