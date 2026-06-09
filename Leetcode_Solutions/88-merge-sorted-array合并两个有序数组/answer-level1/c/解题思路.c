### 解题思路
插入方法：双指针法，遇到nums1[i]>nums2[j]，nums1从i开始后移1个元素，并将nums2[j]插在i的位置，i和j都更新；如果nums1[i]<=nums2[j]，i更新

插入的两个阶段：
1、如果nums2里没有比nums1大的元素，遍历到nums1结尾插入就OK了。
2、如果遍历到nums1的结尾，nums2仍有元素未插入：将nums2剩余的元素插入到nums1的结尾

### 代码

```c
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int i, j, k;
    int add_num = 0;

    if (n == 0) {
        return;
    }

    for (i = 0, j = 0; (i < m + add_num) && (j < n);) {
        if (nums1[i] <= nums2[j]) {
            i++;
        }
        else {
            for (k = m - 1 + add_num; k >= i; k--) {
                nums1[k + 1] = nums1[k];                
            }
            nums1[i] = nums2[j];
            add_num++;
            j++;
            i++;
        }
    }

    for (k = i; k < nums1Size; k++) {
        if (j < n) {
            nums1[k] = nums2[j++];
        }        
    }

}
```