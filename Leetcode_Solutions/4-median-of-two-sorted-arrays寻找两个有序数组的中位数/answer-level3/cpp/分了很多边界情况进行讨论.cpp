### 解题思路
最根本的思路还是依靠划分左右两部分来做（最头疼的是边界处理问题，这个问题自己做的很糟糕）
核心思路：左部分的的数小于右部分的数，然后分奇偶两种情况
### 代码

```cpp
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int k = (m + n) / 2;
        int p = (m + n) % 2;   //判断余数

        if (m == 0)    //处理某一个数组为空的情况
        {
            if (p == 1)
                return nums2[k];
            else
                return (nums2[k - 1] + nums2[k]) / 2.0;
        }

        if (n == 0)
        {
            if (p == 1)
                return nums1[k];
            else
                return (nums1[k - 1] + nums1[k]) / 2.0;
        }

        if (nums1[m - 1] <= nums2[0])    //处理某一个数组全部大于或小于另一个数组的情况
        {
            nums2.insert(nums2.begin(), nums1.begin(), nums1.end());
            if (p == 1)
                return nums2[k];
            else
                return (nums2[k - 1] + nums2[k]) / 2.0;
        }
        if (nums1[0] >= nums2[n - 1])
        {
            nums1.insert(nums1.begin(), nums2.begin(), nums2.end());
            if (p == 1)
                return nums1[k];
            else
                return (nums1[k - 1] + nums1[k]) / 2.0;
        }

        if (m > n)    //保持nums1的数量小于nums2
        {
            vector <int> mid(nums2);
            nums2 = nums1;
            nums1 = mid;
            int k = m;
            m = n;
            n = k;
        }

        if (nums2[k - 1] <= nums1[0])    //nums1取0个数的情况
        {
            if (p == 1)
                return min(nums1[0], nums2[k]);
            else
                return (nums2[k - 1] + min(nums1[0], nums2[k])) / 2.0;
        }

        int left_max1, left_max2, right_min1, right_min2;   //切开的位置
        for (int i = 0; i <= k; i++)
        {
            left_max1 = nums1[i];   //保持左侧有k个数
            int j = k - i - 1;
            if (j == 0)    //若nums1只有一个数，nums2只有两个数
            {
                if (p == 1)
                    return nums1[0];
                else
                    return (nums1[0] + nums2[0]) / 2.0;
            }
            left_max2 = nums2[j - 1];

            if (i == m - 1)    //nums1已经遍历到最右侧的情况
            {
                if (p == 1)
                    return nums2[k - m];
                else
                    return (max(nums2[k - m - 1], nums1[m - 1]) + nums2[k - m]) / 2.0;
            }
            right_min1 = nums1[i + 1];
            right_min2 = nums2[j];

            if (left_max1 <= right_min2 && left_max2 <= right_min1)
            {
                if (p == 1)
                    return min(right_min1, right_min2);
                else
                    return (min(right_min1, right_min2) + max(left_max1, left_max2)) / 2.0;
            }


        }

        return 0;
    }
};
```