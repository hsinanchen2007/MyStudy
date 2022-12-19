### 解题思路

### 代码

```cpp
class Solution {
public:
    void Merge(vector<int>& nums, int l, int mid, int r) {
        int len = r - l + 1;
        
        vector<int> tmp(len);
        
        int left = l;
        int right = mid + 1;
        int i = 0;
        while (left <= mid && right <= r) {
            if (nums[left] < nums[right]) {
                tmp[i++] = nums[left++];
            } else {
                tmp[i++] = nums[right++];
            }
        }
        while (left <= mid) {
            tmp[i++] = nums[left++];
        }
        while (right <= r) {
            tmp[i++] = nums[right++];
        }
        for (int j = 0; j < i; j++) {
            nums[l + j] = tmp[j];
        }
    }
    void MergeSort(vector<int>& nums, int l, int r) {
        if (l == r) {
            return;
        }
        int mid = (l + r) / 2;
        
        MergeSort(nums, l, mid);
        MergeSort(nums, mid + 1, r);
        Merge(nums, l, mid, r);
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size = nums2.size();
        for (int i = 0; i < size; i++) {
            nums1.push_back(nums2[i]);
        }
        MergeSort(nums1, 0, nums1.size() - 1);
        int size1 = nums1.size();
        
        if (size1 % 2 == 1) {
            return nums1[size1 / 2] * 1.0;
        } else {
            return (nums1[size1 / 2] + nums1[size1 / 2 - 1]) * 1.0 / 2;
        }
    }
};
```