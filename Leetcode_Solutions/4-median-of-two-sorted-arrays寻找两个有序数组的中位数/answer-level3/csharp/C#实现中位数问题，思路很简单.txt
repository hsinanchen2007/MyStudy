nums1 m   nums2 n
先假定 (m+n)/2 为偶数
那么可以判断出 **左边需要 nums1 里前i个数据，nums2中前j个数据**

因为是中位数，所以 **i + j = (m+n)/2**
确定了 i 既可以 确定 j 的取值，

中位数特点： **左边最大的数据，要小于或等于右边最小的数据**

max(nums1[i-1],nums2[j-1]) <= min(nums1[i],nums2[j])
因为 nums1[i-1]<=nums1[i] , nums2[j-1]<=nums2[j]
=> 需要满足 **nums1[i-1] <= nums2[j] && nums2[j-1] <= nums1[i]**

并且如果 nums1[i-1]>nums2[j] 则可知 nums2[j-1] <= nums1[i]必定成立，

类推，**上述两条件一个不成立，则另一个一定成立**

**二分法循环m**，如果 nums1[i-1]>nums2[j]  i要减小，j要增大  如果 nums2[j-1] > nums1[i] j要 减小，i要增大

**实现过程中需要注意各种 i, j 的边界问题**

下面贴代码，完全按照思路来，但是没有进行很好优化，各位担待

public double FindMedianSortedArrays(int[] nums1, int[] nums2)
    {
        //根据长度获取中位数两边数字的个数
        int midNum = (nums1.Length + nums2.Length) / 2;
        int i = nums1.Length / 2, j = midNum - i;
        int low_i = 0, high_i = nums1.Length;

        for (; i <= nums1.Length;)
        {
            if (i > 0 && j < nums2.Length && nums1[i - 1] > nums2[j])
            {
                high_i = i - 1;
                i = (low_i + high_i) / 2;
                j = midNum - i;
                while (j > nums2.Length)
                {
                    low_i = i + 1;
                    i = (high_i + low_i) / 2;
                    j = midNum - i;
                }
                continue;
            }

            if (i < nums1.Length && j > 0 && nums2[j - 1] > nums1[i])
            {
                low_i = i + 1;
                i = (high_i + low_i) / 2;
                j = midNum - i;
                while (j < 0)
                {
                    high_i = i - 1;
                    i = (low_i + high_i) / 2;
                    j = midNum - i;
                }
                continue;
            }

            break;
        }

        if ((nums1.Length + nums2.Length) % 2 == 0)
        {
            return (
                        Math.Max(i > 0 ? nums1[i - 1] : nums2[j - 1], j > 0 ? nums2[j - 1] : nums1[i - 1]) + 
                        Math.Min(i < nums1.Length ? nums1[i] : nums2[j], j < nums2.Length ? nums2[j] : nums1[i])
                    ) / 2.0;
        }
        else
        {
            return Math.Min(i < nums1.Length ? nums1[i] : nums2[j], j < nums2.Length ? nums2[j] : nums1[i]) / 1.0;
        }
    }