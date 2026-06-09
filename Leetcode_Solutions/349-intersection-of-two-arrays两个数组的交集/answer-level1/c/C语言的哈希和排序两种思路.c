### 解题思路
method 1:
使用 NLOGN 的排序，再双指针遍历，遇到交集输出，且仅输出一次
任意指针走完，都算循环结束
T: 主要耗在排序上，O(NLOGN)
S: O(1)

method 2:
简单哈希造表，遍历第一个数组，出现过，对应元素值作为哈希地址，哈希表置一
遍历第二个表，对应哈希位置为 1，则输出，并清 0，确保输出一次
典型的空间换时间，关键在于元素出现范围
T: O(numsSize1 + numsSize2)
S: O(M) M 为元素出现范围

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

//  method 1: 排序
// void adjustDown (int *a, int k, int n) {
//     int temp = a[k - 1];
//     for (int i = k * 2; i <= n; i = 2 * k) {
//         if ( i + 1 <= n && a[i + 1 - 1] > a[i -1]) ++i;
//         if (temp >= a[i - 1]) break;
//         a[k - 1] = a[i - 1];
//         k = i;
//     }
//     a[k - 1] = temp;
// }

// void buildHeap (int *a, int n) {
//     for (int i = n / 2; i >= 1; --i) {
//         adjustDown(a, i, n);
//     }
// }

// void heapSort (int *a, int n) {
//     buildHeap(a, n);
//     for (int i = n - 1; i >= 1; --i) {
//         int temp = a[0];
//         a[0] = a[i];
//         a[i] = temp;
//         adjustDown(a, 1, i);
//     }
// }

// int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
//     int *res = (int *) malloc(1 * sizeof(int));
//     heapSort(nums1, nums1Size);
//     heapSort(nums2, nums2Size);
//     int length = 0;
//     for (int i = 0, j = 0; i < nums1Size && j < nums2Size;) {
//         if (nums1[i] > nums2[j]) ++j;
//         else if (nums1[i] < nums2[j]) ++i;
//         else {// push in, 同时跳过所有相等的元素
//             int data = nums1[i];
//             length++;
//             res = realloc(res, length * sizeof(int));
//             res[length - 1] = data;
//             while (i < nums1Size && nums1[i] == data) ++i;
//             while (j < nums2Size && nums2[j] == data) ++j;
//         }
//     }

//     returnSize[0] = length;
//     return res;
// }

// method 2: hash
int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    int *res = (int *) malloc(1 * sizeof(int));
    int hash[1000] = {0};

    // build hash list
    for (int i = 0; i < nums1Size; ++i) hash[nums1[i]] = 1;

    int length = 0;
    for (int i = 0; i < nums2Size; ++i) {
        if (hash[nums2[i]] == 1) {
            res = (int *)realloc(res, ++length * sizeof(int));
            res[length - 1] = nums2[i];
            hash[nums2[i]] = 0;
        }
    }

    returnSize[0] = length;
    return res;
}
```