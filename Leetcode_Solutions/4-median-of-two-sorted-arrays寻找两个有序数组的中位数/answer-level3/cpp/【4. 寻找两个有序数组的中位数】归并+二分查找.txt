## 思路一：归并排序
### 代码
时间复杂度：O(m + n)
空间复杂度：O(m + n)
```c++
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size1 = nums1.size(), size2 = nums2.size();
        vector<int> merge;
        int i = 0, j = 0;
        double res;
        while (i < size1 && j < size2) {
            if (nums1[i] <= nums2[j]) {
                merge.push_back(nums1[i++]);
            } else {
                merge.push_back(nums2[j++]);
            }
        }
        while (i < size1) {
            merge.push_back(nums1[i++]);
        }
        while (j < size2) {
            merge.push_back(nums2[j++]);
        }
        if ((size1 + size2) & 1 == 1) {
            res = merge[(size1 + size2) / 2];
        } else {
            res = (merge[(size1 + size2) / 2] + merge[(size1 + size2 - 1) / 2]) / 2.0;
        }
        return res;
    }
};
```

## 思路二：二分查找
参考 ：[[LeetCode] 4. Median of Two Sorted Arrays 两个有序数组的中位数](https://www.cnblogs.com/grandyang/p/4465932.html)

### 代码
时间复杂度：O(log(m + n))
```c++
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size1 = nums1.size(), size2 = nums2.size();
        int left = (size1 + size2 + 1) / 2, right = (size1 + size2 + 2) / 2;
        return (findKth(nums1, 0, nums2, 0, left) + findKth(nums1, 0, nums2, 0, right)) / 2.0;
    }
    int findKth(vector<int>& num1, int i, vector<int>& num2, int j, int k) {
        if (i >= num1.size()) return num2[j + k - 1];
        if (j >= num2.size()) return num1[i + k - 1];
        if (k == 1) return min(num1[i], num2[j]);
        int midLeft = (i + k / 2 - 1 < num1.size()) ? num1[i + k / 2 - 1] : INT_MAX;
        int midRight = (j + k / 2 - 1 < num2.size()) ? num2[j + k / 2 - 1] : INT_MAX;
        if (midLeft < midRight) {
            return findKth(num1, i + k / 2, num2, j, k - k / 2);
        } else {
            return findKth(num1, i, num2, j + k / 2, k - k / 2);
        }
    }
};
```


