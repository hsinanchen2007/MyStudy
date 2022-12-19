### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        bool flag = (nums1.size() + nums2.size()) % 2;    // 奇数

        int p1 = 0, p2 = 0;     // nums1和nums2位置
        int res = 0;
        int h_pos = (nums1.size() + nums2.size()) / 2;
        while((p1 + p2) <= h_pos && p1 < nums1.size() && p2 < nums2.size())
        {
            if(p1 + p2 == h_pos)
            {
                if(flag)
                {
                    return min(nums1[p1], nums2[p2]);
                }
                else
                {
                    return (static_cast<double>(res) + min(nums1[p1], nums2[p2])) / 2;
                }
            }
            else
            {
                res = min(nums1[p1], nums2[p2]);
                if(nums1[p1] < nums2[p2])
                {
                    ++p1;
                }
                else
                {
                    ++p2;
                }
            }
        }

        if(p1 < nums1.size())
        {
            if(flag)
            {
                return nums1[h_pos - p2];
            }
            else
            {
                if(h_pos - p2 - 1 >= 0)
                {
                    res = max(res, nums1[h_pos - p2 -1 ]);
                    return (static_cast<double>(res) + nums1[h_pos - p2]) / 2; 
                }
                return (static_cast<double>(res) + nums1[h_pos - p2]) / 2;
            }
        }
        else
        {
            if(flag)
            {
                return nums2[h_pos - p1];
            }
            else
            {
                if(h_pos - p1 - 1 >= 0)
                {
                    res = max(res, nums2[h_pos - p1 -1 ]);
                    return (static_cast<double>(res) + nums2[h_pos - p1]) / 2;
                }
                return (static_cast<double>(res) + nums2[h_pos - p1]) / 2;
            }
        }
    }
};
```