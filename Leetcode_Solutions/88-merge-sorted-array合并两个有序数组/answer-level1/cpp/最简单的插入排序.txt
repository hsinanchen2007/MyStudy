## 算法

`nums1` 和 `nums2` 都是有序数组，最简单的插入排序，不知道你们为什么写的那么复杂。虽然题目要求是在 `nums1` 原址排序，但是很显然创建一个新的数组时间复杂度更低（数组的拷贝也需要大量的时间）。

这一题的关键在于如何降低数组拷贝的时间开销，而不是真的让你们排序。

时间复杂度 `O(n)`，空间开销 `O(n)`。空间换时间。

## 代码

```cpp
class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        vector<int> num;
        num.reserve(m);

        for (int i = 0, j = 0; i < m || j < n;)
        {
            int n1 = (i < m) ? nums1[i] : numeric_limits<int>::max();
            int n2 = (j < n) ? nums2[j] : numeric_limits<int>::max();
            if (n1 < n2)
            {
                num.push_back(n1);
                i++;
            }
            else
            {
                num.push_back(n2);
                j++;
            }
        }

        nums1.swap(num);
    }
};
```