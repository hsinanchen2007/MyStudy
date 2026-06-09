```cpp
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }
        int N = nums1.size();
        int M = nums2.size();
        int half = (N + M) / 2;
        int low = 0;
        int high = N;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int t = half - mid;
            int lmax1 = (mid - 1 >= 0) ? nums1[mid - 1] : INT_MIN;
            int rmin1 = (mid < N) ? nums1[mid] : INT_MAX;
            int lmax2 = (t - 1 >= 0) ? nums2[t - 1] : INT_MIN;
            int rmin2 = (t < M) ? nums2[t] : INT_MAX;
            if (lmax1 > rmin2) {
                high = mid - 1;
            } else if (lmax2 > rmin1) {
                low = mid + 1;
            } else {
                low = high = mid;
                break;
            }
        }
        int u = low;
        int v = half - low;
        int l = max(
                u - 1 >= 0 ? nums1[u - 1] : INT_MIN,
                v - 1 >= 0 ? nums2[v - 1] : INT_MIN);
        int r = min(
                u < N ? nums1[u] : INT_MAX,
                v < M ? nums2[v] : INT_MAX);
        if ((N + M) % 2 == 1) return r;
        return (l + r) * 1.0 / 2;
    }
};
```
![image.png](https://pic.leetcode-cn.com/d0d2b56764e447dbc37cf580283fd495e63fc4a36f3d978fece1f7dfbeb42777-image.png)
