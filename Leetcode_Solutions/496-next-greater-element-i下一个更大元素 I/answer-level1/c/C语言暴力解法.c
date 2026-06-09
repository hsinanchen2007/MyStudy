### 解题思路
用一个flag表示是否在nums2中找到nums1[i]，然后找到比他大的数返回

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* nextGreaterElement(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    *returnSize = nums1Size;
    int* res = (int*)malloc(sizeof(int) * nums1Size);
    int flag = 0;
    int i, j;

    for(i = 0; i < nums1Size; i++) {
        for(j = 0; j < nums2Size; j++) {
            if(nums1[i] == nums2[j]) {
                flag = 1;
                continue;
            } else if(nums1[i] < nums2[j] && flag == 1) {
                res[i] = nums2[j];
                break;
            } else {
                continue;
            }
        }
        if(j == nums2Size) {
            res[i] = -1;
            printf("%d", res[i]);
        }
        flag = 0;
    }
    return res;
}
```