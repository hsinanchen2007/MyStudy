nums2数组接在nums1后面，从nums2的第一个元素开始，插入nums1的数组中
![image.png](https://pic.leetcode-cn.com/4f4c521b9927a07c811d85418eb00180f798f0f232aedaf8b282098482d800a7-image.png)
```
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    int i, j;
    for(i = m; i < m + n; i++){
        int temp = nums2[i - m];
        for(j = i; j>0 && nums1[j-1] > temp; j--)
            nums1[j] = nums1[j-1];
        nums1[j] = temp;
    }
}
```
