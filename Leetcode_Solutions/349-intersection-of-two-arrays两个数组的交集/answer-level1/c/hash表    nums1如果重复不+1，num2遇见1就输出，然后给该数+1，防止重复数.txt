```
#define g_size 100001

int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    if (nums1Size == 0 || nums2Size == 0) {
        * returnSize = 0;
    }
    int idx = 0;
    int hashmap[g_size] = { 0 };
    int *ret = (int *)malloc(sizeof(int) * (nums1Size < nums2Size ? nums1Size : nums2Size));
    for (int i = 0; i < nums1Size; i++) {
        if (hashmap[nums1[i]] == 0) {
            hashmap[nums1[i]]++;
        }
    }
    for (int i = 0; i < nums2Size; i++) {
        if (hashmap[nums2[i]] == 1) {
            ret[idx++] = nums2[i];
            hashmap[nums2[i]]++;
        }
    }
    * returnSize = idx;
    return ret;
}
```
