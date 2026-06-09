### 解题思路
就是一个合并数组的操作，合并后求数组的中值就可以。

### 代码

```cpp
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size1 = nums1.size();
        int size2 = nums2.size();
        vector<int> tmp;
        int i = 0, j = 0, z = 0;
        while(i < size1 && j < size2) {
            if (nums1[i] <= nums2[j]) {
                tmp.push_back(nums1[i]);
                i++;
            } else {
                tmp.push_back(nums2[j]);
                j++;
            }
        }
        while(i < size1) {
            tmp.push_back(nums1[i]);
            i++;
        }
        while(j < size2) {
            tmp.push_back(nums2[j]);
            j++;
        }
        int size = tmp.size();
        if ((size & 1) == 0) {
            int middle = size / 2;
            return (double(tmp[middle]) + double(tmp[middle - 1])) / 2;
        } else {
            int middle = size / 2;
            return double(tmp[middle]);
        }
    }
};
```