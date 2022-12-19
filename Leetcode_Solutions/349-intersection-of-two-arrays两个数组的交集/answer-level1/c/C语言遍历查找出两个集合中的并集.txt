最简单的思路： 遍历数组1，如果数组1的元素在素组二中已经存在，则添加该数据到结果数组中。
这里注意两个地方需要去重：
1. 如果数组1的数据已经添加到结果集，则不用再添加
2. 如果数组1的数据在数组2中已经存在，则break，防止数组2后边又出现相同的数据，重复添加。

#  define min(x, y) (((x) > (y)) ? (y) : (x))

/**
* Note: The returned array must be malloced, assume caller calls free().
*/
int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int  maxSize = min(nums1Size, nums2Size);
    printf("%d %d %d\n", maxSize, nums1Size, nums2Size);
    int *returnNums = (int *)malloc(maxSize * sizeof(int));
    int index = 0;
    for (int i = 0; i < nums1Size; i++) {
        int  exists = 0;
        if (nums1 + i == NULL) {
            break;
        }
        for (int k = 0; k < index; ++k) {
            if (returnNums[k] == nums1[i]) {
                exists = 1;
                continue;
            }
        }
        if (exists) {
            continue;
        }

        for (int j = 0; j < nums2Size; j++) {
            if (nums2 + j == NULL) {
                break;
            }
            if (nums2[j] == nums1[i]) {
                printf("%d\n", index);
                returnNums[index] = nums1[i];
                ++index;
                break;
            }
        }
    }
    *returnSize = index;
    return returnNums;
}
