### 解题思路
合并两个有序数组后，去中间值

### 代码

```cpp
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int nums1Size = nums1.size();
        int nums2Size = nums2.size();
        if (nums1Size + nums2Size == 0) {
            return 0.0;
        }
        int index1 = 0;
        int index2 = 0;
        vector<int> vecResult;
        while (index1 < nums1Size || index2 < nums2Size) {
            if (index1 < nums1Size && index2 < nums2Size ) {
                if (nums1[index1] < nums2[index2]) {
                    vecResult.push_back(nums1[index1]);
                    index1++;
                } else {
                    vecResult.push_back(nums2[index2]);
                    index2++;
                }
            } else if(index1 >= nums1Size) {
                vecResult.push_back(nums2[index2]);
                index2++;
            } else {
                vecResult.push_back(nums1[index1]);
                index1++;
            }
        }
        int medimIndex = (nums1Size + nums2Size) / 2;
        if ((nums1Size + nums2Size) % 2 == 1) {
            // 奇数
            return (double)vecResult[medimIndex];
        }
        return ((double)vecResult[medimIndex] + (double)vecResult[medimIndex - 1]) / 2.0;
    }
};
```