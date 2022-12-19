### 解题思路
之前写的太蠢了，借鉴别人的重新写了一遍

### 代码

```cpp
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int p1 = 0;                                     // nums1的位置
        int p2 = 0;                                     // nums2的位置
        int vleft = 0;                                  // 左值
        int vright = 0;                                 // 右值
        int half = (nums1.size() + nums2.size()) / 2;   // 中值位置

        while(p1 + p2 <= half)
        {
            vleft = vright;
            if(p2 >= nums2.size() || ( p1 < nums1.size() && nums1[p1] < nums2[p2]))      // 当nums2的值已经取完，或者nums1的值没有取完且nums1[p1] < nums2[p2]，从nums1取
            {
                vright = nums1[p1++];
            }
            else
            {
                vright = nums2[p2++];
            }
        }

        if((nums1.size() +nums2.size()) % 2)            // 奇数直接返回
        {
            return vright;
        }

        return (static_cast<double>(vleft) + vright) / 2;
    }
};
```