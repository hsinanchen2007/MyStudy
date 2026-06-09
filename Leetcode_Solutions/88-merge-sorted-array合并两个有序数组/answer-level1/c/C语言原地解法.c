### 解题思路
(1)先将nums1的数据拷贝到nums1后侧(从后向前拷贝)：
nums1[nums1Size - 1] = nums1[m - 1]；
nums1[nums1Size - 2] = nums1[m - 2]；
...
nums1[nums1Size - m] = nums1[0] 

(2)再按序比较nums1和nums2数据，重写nums1数组.
nums1下标从nums1Size - m开始；
nums2下标从0开始；

### 代码

```c
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    for(int i = 1; i <= m; i++) {
        nums1[nums1Size - i] = nums1[m - i];
    }
    int p1 = nums1Size - m,p2 = 0;
    for(int i = 0; i < nums1Size; i++) {
        if(p2 < n && p1 < nums1Size){
            nums1[i] = (nums1[p1] < nums2[p2])?nums1[p1++]:nums2[p2++];
        } 
        else if(p1 == nums1Size) {
            nums1[i] = nums2[p2++];
        }
    }
}
```