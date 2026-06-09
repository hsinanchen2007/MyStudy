
``` c++
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int l1 = 0, l2 = 0;
        int len1 = nums1.size();
        int len2 = nums2.size();
        // 两个中位数的位置k，k2 可能重叠
        int k = (len1 + len2 + 1) >> 1;
        int k2 = (len1 + len2 + 2) >> 1;
        
        while (true) {
            // 其中一个数组被用完
            if (l1 == len1) {
                if (k == k2) return nums2[k - len1 - 1];
                else return (nums2[k - len1 - 1] + nums2[k - len1]) * 0.5;
            }
            if (l2 == len2) {
                if (k == k2) return nums1[k - len2 - 1];
                else return (nums1[k - len2 - 1] + nums1[k - len2]) * 0.5;
            }
            // 还剩一个数
            if (l1 + l2 == k - 1) {
                if (k == k2) return min(nums1[l1], nums2[l2]);
                else {
                    vector<int> temp = {nums1[l1], nums2[l2]};
                    if (l1 + 1 < len1) temp.push_back(nums1[l1 + 1]);
                    if (l2 + 1 < len2) temp.push_back(nums2[l2 + 1]);
                    sort(temp.begin(), temp.end());
                    return (temp[0] + temp[1]) * 0.5;
                }
            }
            // 更新剩下数的一半，比较应该推进哪个指针
            // 第 n 个数的下标是 n - start - 1
            int left = (k - l1 - l2) >> 1;
            int mid1 = min(l1 + left - 1, len1 - 1); 
            int mid2 = min(l2 + left - 1, len2 - 1); 
            if (nums1[mid1] > nums2[mid2]) l2 = mid2 + 1;
            else l1 = mid1 + 1;
        }
        return -1;
    }
};
```
