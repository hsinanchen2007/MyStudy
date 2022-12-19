### 解题思路
中位数下标包括(n+m-1)/2和(n+m)/2，如果n+m是奇数，就只有一个数字；如果是偶数就是2个数字
现在需要找到较低的数字下标p=(n+m-1)/2在什么位置，这里需要2个辅助下标num1中偏移i和num2中偏移j，使p=i+j，需要满足以下几个点：
- num1[i] > num2[j-1]
- num2[j] > num1[i-1]
这个时候在num1用二分查找找到i的位置即可（在num2找j的位置一样），时间复杂度O(log(min(n, m)))
### 代码

```cpp
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size(), i = 0, j = 0;
        bool flag = (n + m) & 1; // 是否是奇数
        int p = (n + m - 1) / 2; // 中位数左边的下标
        int low = 0, high = n - 1, mid;
        while (m >= 1 && low <= high) {
            mid = (low + high) / 2;
            // 这里二分查找num1，如果num1[i] <= num2[j-1]，说明i的值小了
            if (p - mid - 1 >= m || (p - mid - 1 >= 0 && nums1[mid] <= nums2[p - mid - 1])) {
                low = mid + 1;
                i = low;
            } else {
                high = mid - 1;
            }
        }
        if (p - i >= m) {
            j = m;
            i = p - j;
        } else j = p - i;
        double ans = 0;
        if (i >= n) ans = flag ? nums2[j] : (nums2[j] + nums2[j + 1]) / 2.0;
        else if (j >= m) ans = flag ? nums1[i] : (nums1[i] + nums1[i + 1]) / 2.0;
        else if(flag) ans = min(nums1[i], nums2[j]);
        else if (i + 1 < n && nums1[i + 1] < nums2[j]) ans = (nums1[i] + nums1[i + 1]) / 2.0;
        else if (j + 1 < m && nums2[j + 1] < nums1[i]) ans = (nums2[j] + nums2[j + 1]) / 2.0;
        else ans = (nums1[i] + nums2[j]) / 2.0;
        return ans;
    }
};
```