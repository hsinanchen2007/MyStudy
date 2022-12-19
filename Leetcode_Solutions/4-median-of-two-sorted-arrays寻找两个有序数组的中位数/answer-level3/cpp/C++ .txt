## 方法一
```
class Solution
{
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        vector<int> v;

        size_t len1 = nums1.size();
        size_t len2 = nums2.size();
        size_t i = 0;
        size_t j = 0;

        while ((i < len1) && (j < len2))
        {
            if (nums1[i] <nums2[j] )
            {
                v.push_back(nums1[i++]);
            }
            else
            {
                v.push_back(nums2[j++]);
            }
        }

        while (i < len1)
        {
            v.push_back(nums1[i++]);
        }

        while (j < len2)
        {
            v.push_back(nums2[j++]);
        }

        if ((v.size() & 1) == 0)
            return (v[(len1 + len2) / 2] + v[(len1 + len2) / 2 - 1]) * 0.5;
        else
            return v[(len1 + len2) / 2];
    }
};
```

> 复杂度分析

- 时间复杂度： O(m+n)
- 空间复杂度： O(m+n)

## 方法二
```
class Solution
{
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        size_t m = nums1.size();
        size_t n = nums2.size();
        size_t len = m + n;

        size_t start1 = 0;
        size_t start2 = 0;

        int left = 0;
        int right = 0;

        for (size_t i=0; i<=len/2; ++i)
        {
            left = right;
            if ((start1 < m) && (start2 >= n || nums1[start1] < nums2[start2]))
            {
                right = nums1[start1++];
            }
            else
            {
                right = nums2[start2++];
            }
        }
        
        if ((len & 1) == 0)
            return (left + right) * 0.5;
        else 
            return right;
    }
};
```
> 复杂度分析

- 时间复杂度： O(m+n)
- 空间复杂度： O(1)

## 方法三
```
class Solution
{
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        size_t n = nums1.size();
        size_t m = nums2.size();

        /*
         * 1. 当出现偶数集合时：v[1,2,3,4]
         *  left  = (4+1)/2 = 2;
         *  right = (4+2)/2 = 3;
         *
         * 2. 当出现奇数集合时：v[1,2,3]
         *  left  = (3+1)/2 = 2;
         *  right = (3+2)/2 = 2;
         *
         * 3. (getKth(left) + getKtn(right)) / 2.0;
         */
        size_t left = (n + m + 1) / 2;
        size_t right = (n + m + 2) / 2;

        return (getKth(nums1, 0, n-1, nums2, 0, m-1, left) + getKth(nums1, 0, n-1, nums2, 0, m-1, right)) * 0.5;
    }

    int getKth(vector<int>& nums1, size_t begin1, size_t end1, vector<int>& nums2, size_t begin2, size_t end2, size_t k)
    {
        size_t len1 = end1 - begin1 + 1;
        size_t len2 = end2 - begin2 + 1;

        /*
         * 边界条件：1. 某一数组为空; 2. K = 1
         */
        if (len1 == 0)
            return nums2[begin2 + k - 1];
        else if (len2 == 0)
            return nums1[begin1 + k - 1];
        else if (k == 1)
            return min(nums1[begin1], nums2[begin2]);

        size_t i = begin1 + min(len1, k/2) - 1;
        size_t j = begin2 + min(len2, k/2) - 1;

        if (nums1[i] < nums2[j])
            return getKth(nums1, i+1, end1, nums2, begin2, end2, k-(i-begin1+1));
        else
            return getKth(nums1, begin1, end1, nums2, j+1, end2, k-(j-begin2+1));
    }
};
```
> 复杂度分析

- 时间复杂度： O(log(m+n))
- 空间复杂度： O(1) 【尾递归】

## 方法四
```
class Solution
{
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        size_t m = nums1.size();
        size_t n = nums2.size();

        if (m > n)
        {
            return findMedianSortedArrays(nums2, nums1);
        }

        for (size_t iMin=0, iMax=m, halfLen=(m+n+1)/2; iMin<=iMax; /**/)
        {
            size_t i = (iMin + iMax)/2;
            size_t j = halfLen - i;

            if ((i < iMax) && (nums2[j-1] > nums1[i]))
            {
                iMin = i + 1;
            }
            else if ((i > iMin) && (nums1[i-1] > nums2[j]))
            {
                iMax = i - 1;
            }
            else
            {
                int maxLeft = 0;
                if (i == 0)
                    maxLeft = nums2[j-1];
                else if (j == 0)
                    maxLeft = nums1[i-1];
                else
                    maxLeft = max(nums1[i-1], nums2[j-1]);
                if (((m + n) % 2) == 1)
                    return maxLeft;

                int minRight = 0;
                if (i == m)
                    minRight = nums2[j];
                else if (j == n)
                    minRight = nums1[i];
                else
                    minRight = min(nums1[i], nums2[j]);

                return (maxLeft + minRight) * 0.5;
            }
        }

        return 0.0;
    }    
};
```

- 时间复杂度： O(log(m+n))
- 空间复杂度： O(1) 

