### 解题思路
给定两个数组，编写一个函数来计算它们的交集。

示例 1:

输入: nums1 = [1,2,2,1], nums2 = [2,2]
输出: [2]

示例 2:

输入: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
输出: [9,4]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/intersection-of-two-arrays
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int com(int *a, int *b){
    return *a - *b;
}
int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    int i, j, k=0;
    int *res = malloc(nums1Size * sizeof(int));

    if(nums1Size == 0 || nums2Size == 0){
        *returnSize = 0;
        return NULL;
    }
    qsort(nums1, nums1Size, sizeof(int), com);

    for(j=0;j < nums2Size; j++) {
                if(nums1[0] == nums2[j])
                    break;
    }
    if(j < nums2Size)
        res[k++] = nums1[0];

    for (i=1; i < nums1Size; i++) {
        if (nums1[i] != nums1[i-1]) {
            for(j=0;j < nums2Size; j++) {
                if(nums1[i] == nums2[j])
                    break;
            }
            if(j < nums2Size)
                res[k++] = nums1[i];
        }
    }
    *returnSize = k;
    return res;
}
```