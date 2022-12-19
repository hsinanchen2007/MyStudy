### 解题思路
给你两个有序整数数组 nums1 和 nums2，请你将 nums2 合并到 nums1 中，使 num1 成为一个有序数组。

 

说明:

初始化 nums1 和 nums2 的元素数量分别为 m 和 n 。
你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2 中的元素。
 

示例:

输入:
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6],       n = 3

输出: [1,2,2,3,5,6]



### 代码

```c
int cmp(void * a, void * b){
    return *(int *)a - *(int *)b;
}

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    int i,j;

    for (i = 0; i < n; i++){
        nums1[m+i] = nums2[i];
    }

    qsort(nums1,m+n, sizeof(int),cmp);
    //for (i = 0; i < m + n; i++){
      //  printf("i=%d %d\n",i, nums1[i]);
    //}
    return;
}
```