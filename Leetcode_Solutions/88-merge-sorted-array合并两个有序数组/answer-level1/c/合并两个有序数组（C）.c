### 解题思路
方法一：采用插入排序的思想，将nums2中的元素插入到nums1中的有序表中即可。
方法二：类似于归并排序，从尾部合并两个有序表。

### 代码
# 插入排序

```c
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    if(nums1Size == 0 || nums2Size == 0 || n == 0)
        return;
    if(m == 0){
        for(int i = 0; i < n; i++){
            nums1[i] = nums2[i];
        }
        return;
    }
    int i, j, l = m;
    for(i = 0; i < n; i++){
        for(j = l - 1; j >= 0 && nums1[j] > nums2[i]; j--){
            nums1[j+1] = nums1[j];
        }
        nums1[j+1] = nums2[i];
        l++;   //每次插入后nums1有序部分长度加1
    }
}
```
# 从尾部归并
```
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    if(nums1Size == 0 || nums2Size == 0 || n == 0)
        return;
    if(m == 0){
        for(int i = 0; i < n; i++){
            nums1[i] = nums2[i];
        }
        return;
    }
    int i = m -1, j = n - 1, p = nums1Size - 1;
    while(i >= 0 && j >= 0){
        if(nums1[i] > nums2[j]){
            nums1[p--] = nums1[i--];
        }
        else{
            nums1[p--] = nums2[j--];
        }
    }
    while(i >= 0){
        nums1[p--] = nums1[i--];
    }
    while(j >= 0){
        nums1[p--] = nums2[j--];
    }

}
```
