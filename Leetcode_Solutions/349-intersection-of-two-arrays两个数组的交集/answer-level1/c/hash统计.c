/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    int i, count1[9999] = {0}, count2[9999] = {0};
    for (i = 0; i < nums1Size; i++) {
        if (count1[nums1[i]] == 0) {
            count1[nums1[i]]++;
        }
    }

    for (i = 0; i < nums2Size; i++) {
        if (count2[nums2[i]] == 0) {
            count2[nums2[i]]++;
        }
    }

    int count = 0;

    int size = nums1Size < nums2Size ? nums1Size : nums2Size;
    int* ans = (int *)malloc(sizeof(int) * size);
    int j = 0;
    for (i = 0; i < 9999; i++) {
        if (count1[i] == count2[i] && count1[i] == 1 && count2[i] == 1) {
            count++;
            ans[j++] = i;
        }
    }

    *returnSize = count;
    return ans;
}```
代码块
```
