### 解题思路
此处撰写解题思路
（代码可能不是最优）
核心思想：根据中位数定义，问题等价于在第1个list中取前i个数，第2个list中取j个数，使得i+j=总个数（偶数）/2 或i+j=（总个数（奇数）+1）/2
同时，要求第1个list取出的最大数小于等于第2个list取出后剩余的最小值 & 第2个list取出的最大数小于等于第1个list取出的最小数，这种情况下即为中位数条件。（奇数偶数情况分别讨论即可）

由于i+j个数确定，因此可以看成是查找问题（查找符合要求的数），采用二分查找，对长度较小的list进行二分查找即可。

程序思路：
首先保证查找的list1长度最小；
考虑边界情况，最小list长度为0，直接可输出奇数偶数情况下的中位数；
k为i+j总数，同时满足奇数偶数情况；
对i,j初始化后进行求解：
当i==0情况时，需要判断list1右侧的最小值是否大于list2左侧的最大值，若不是则是初始化的问题，需要将i+1；
当i==m情况时，对应同理。
当i不在边界条件时，按二分法进行查找。


### 代码

```python3
class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:

        m = len(nums1);
        n = len(nums2);
        if m > n:
            return self.findMedianSortedArrays(nums2, nums1);

        if m == 0:
            if (m + n) % 2 == 0:
                return (nums2[math.floor((n - 1) / 2)] + nums2[math.ceil((n - 1) / 2)]) / 2;
            else:
                return nums2[math.ceil((n - 1) / 2)];
        k = int(math.ceil((m + n) / 2));
        flag_min = 0;
        flag_max = m;
        i = flag_min + int(math.ceil((flag_max - flag_min) / 2));

        j = k - i;
        while (flag_min <= flag_max):

            if i == 0:
                if nums1[i] >= nums2[j - 1]:

                    if (m + n) % 2 == 0:
                        if j == n:
                            return (nums1[i] + nums2[j - 1]) / 2.0;
                        else:

                            return (min(nums1[i],nums2[j] )+ nums2[j - 1]) / 2.0;
                    else:

                        return nums2[j - 1];
                else:
                    i = i + 1;
                    j = k - i

            elif i == m:
                if nums1[i - 1] <= nums2[j]:

                    if (m + n) % 2 == 0:
                        if j == 0:
                            return (nums1[i - 1] + nums2[j]) / 2.0;
                        else:
                            return (max(nums1[i - 1], nums2[j - 1]) + nums2[j]) / 2.0
                    else:
                        if j == 0:
                            return nums1[i - 1];
                        else:
                            return max(nums2[j - 1], nums1[i - 1]);
                else:
                    i = i - 1;
                    j = k - i

            if (i - 1 >= 0) & (i <= m - 1) & (j - 1 >= 0) & (j <= n - 1):

                i = flag_min + int(math.ceil((flag_max - flag_min) / 2));
                j = k - i;

                if (i - 1 >= 0) & (i <= m - 1) & (j - 1 >= 0) & (j <= n - 1):
                    if max(nums1[i - 1], nums2[j - 1]) <= min(nums1[i], nums2[j]):
                        if (m + n) % 2 == 0:
                            return (max(nums1[i - 1], nums2[j - 1]) + min(nums1[i], nums2[j])) / 2;
                        else:
                            return max(nums1[i - 1], nums2[j - 1]);
                    elif nums1[i - 1] > nums2[j]:
                        if flag_max - flag_min > 1:
                            flag_max = i;
                        else:
                            flag_max = i - 1;

                    elif nums2[j - 1] > nums1[i]:
                        if flag_max - flag_min > 1:
                            flag_min = i;
                        else:
                            flag_min = i + 1;



```