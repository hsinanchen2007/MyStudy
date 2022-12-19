### 解题思路
数组1后边是空的，两个数组归并就从大的开始往数组1里头塞就完事

### 代码

```c
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    int i = m+n-1;
    n--;m--;
    while(m>=0 && n>=0){
        if(nums1[m]>nums2[n]){
            nums1[i--] = nums1[m--];
        }else{
            nums1[i--] = nums2[n--];
        }
    }
    while(n>=0){
        nums1[i--] = nums2[n--];
    }
}
```