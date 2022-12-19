### 解题思路
此处撰写解题思路
1. 设置三个指针分别指向num1最后一个元素，num2最后一个元素，num1中num1加num2数量的位置
2. 从最后一个元素比较大小，将较大值传到num1，从后到前依次递减
3. 如果其中一个数组已经遍历完成，则直接将另一个数组的依次传入num1
### 代码

```c
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    int i = m - 1, j = n - 1, k = m + n - 1;

    while (k >= 0)
    {
        if (i < 0) nums1[k--] = nums2[j--];
        else if (j < 0) nums1[k--] = nums1[i--];
        else nums1[k--] = (nums1[i] > nums2[j]) ? nums1[i--] : nums2[j--];
    }
    return;
}
```