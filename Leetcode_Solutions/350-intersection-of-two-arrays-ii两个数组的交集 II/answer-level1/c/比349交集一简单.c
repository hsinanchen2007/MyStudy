![image.png](https://pic.leetcode-cn.com/9a27107ee2b78b471ea97a57e912a3fddd72879608a0b35248dd205e1e3922c4-image.png)

我是快排加二分再加归并方法求交集

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void quick_sort(int *nums, int l, int r) {
    if(r < l) return ;
    int i = l, j = r, pivot = nums[l];
    while(i < j) {
        while(i < j && nums[j] >= pivot) j--;
        if(i < j) nums[i++] = nums[j];
        while(i < j && nums[i] <= pivot) i++;
        if(i < j) nums[j--] = nums[i];  
    }
    nums[i] = pivot;
    quick_sort(nums, l, i - 1);
    quick_sort(nums, i + 1, r);
    return ;
}

int binary_search(int *arr, int n, int val) {
    int l = 0, r = n - 1, mid;
    while(l <= r) {
        mid = (l + r) >> 1;
        if(arr[mid] == val) return mid;
        else if(arr[mid] > val) r = mid - 1;
        else l = mid + 1;
    }
    return -1;
}

int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    if(nums1Size == 0 || nums2Size == 0) {
        *returnSize = 0;
        return NULL;
    }    
    quick_sort(nums1, 0, nums1Size - 1);
    quick_sort(nums2, 0, nums2Size - 1);
    int *arr = (int *)malloc(sizeof(int) * nums1Size);
    int i = 0, j = 0, cnt = 0;
    while(i < nums1Size && j < nums2Size) {
        if(nums1[i] == nums2[j]) {
            arr[cnt++] = nums1[i];
            i++;
            j++;
        } else if(nums1[i] > nums2[j]) {
            j++;
        } else i++;
    }
    *returnSize = cnt;
    return arr;
}
```
