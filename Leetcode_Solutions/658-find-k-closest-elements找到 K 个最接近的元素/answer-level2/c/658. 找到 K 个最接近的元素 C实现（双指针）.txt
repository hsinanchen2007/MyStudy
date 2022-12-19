### 解题思路
此处撰写解题思路

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findClosestElements(int* arr, int arrSize, int k, int x, int* returnSize){
    *returnSize = k;
    int idx = 0;
    int mallocSize = sizeof(int) * k;
    int* ans = (int*)malloc(mallocSize);
    int dif = abs(arr[0] - x);
    for (int i = 0; i < arrSize; ++i) {
        int newDif = abs(arr[i] - x);
        if (newDif < dif) {
            idx = i;
            dif = newDif;
        }
    }
    int left = idx;
    int right = idx;
    int dl, dr;
    while (right - left != k - 1) {
        int l = left - 1;
        int r = right + 1;
        if (l < 0) {
            right = r;
            continue;
        }
        if (r >= arrSize) {
            left = l;
            continue;
        }
        if (x * 2 <= arr[r] + arr[l]) {
            left = l;
        } else {
            right = r;
        }
    }
    memcpy(ans, &arr[left], mallocSize);
    return ans;
}
```