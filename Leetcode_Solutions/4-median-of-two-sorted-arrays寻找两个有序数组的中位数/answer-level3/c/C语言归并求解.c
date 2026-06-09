### 解题思路
提前算好求解需要1个还是2个数，以及第1个数在归并后的位置，再使用归并的方式遍历两个数组，取出对应位置的数值计算最后结果。

### 代码

```c
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int i = 0, j = 0, index = 0, findNum = 0, a, b;
    int targetNum = ((nums1Size + nums2Size) % 2 == 0) ? 2 : 1;
    int target = (nums1Size + nums2Size - 1) / 2;
    int find[2];

    while (index < target + targetNum) {
        a = (i < nums1Size) ? nums1[i] : 0x7fffffff;
        b = (j < nums2Size) ? nums2[j] : 0x7fffffff;
        (a < b) ? (i++) : (j++);
        if (index++ >= target) {
            find[findNum++] = (a < b) ? a : b;
        }
    }
    return (targetNum == 1) ? (double)find[0] : ((double)find[0] + find[1]) / 2;
}
```