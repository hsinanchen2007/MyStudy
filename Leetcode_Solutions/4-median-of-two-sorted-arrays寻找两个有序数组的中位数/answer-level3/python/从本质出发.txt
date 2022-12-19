首先理清这道题的**核心思想**：

> 中位数：可以把中位数理解成为一个分隔符，这个分隔符的左半部分与右半部分相等，且左半部分的最大值不大于右半部分的最小值。
>
> 在一个长度为$m$的数组中，$i$共有$m+1$个可能的位置，即$i \in [0,m]$，对于任意的$i$，其将$a[0]...a[i-1]$与$a[i]...a[m-1]$分割开来。对于一个中位数，需要满足以下两点：
>
> - $len(a[0]...a[i-1])=len(a[i]...a[m-1])$，即$len(a_{left})=len(a_{right})$;
> - 当数组$a$有序时，$a[i-1]<a[i]$.

由于我们有两个长度分别为$m,n$的数组$a,b$，所以我们需要同时确定两个分隔符$i$和$j$，使得

- $len(a_{left})+len(b_{left})=len(a_{right})+len(b_{right})$；
- $a[i-1]<b[j],b[j-1]<a[i]$.

当然，同时求解两个变量$i,j$有些繁琐，所以我们使用其中的条件一来作为一个约束，使得整个问题编程只有一个条件一个变量的问题。

>- 当$m+n$为偶数时，$len(a_{left})+len(b_{left})=i+j=(m+n)/2$，即$j=(m+n)/2-i$；
>
>- 当$m+n$为奇数时，我们可以把中位数包含在左边，也可以包含在右边。当在左边时$i+j=(m+n+1)/2=(m+n)/2$，当在右边时，$i+j=(m+n)/2-1=(m+n-2)/2$，显然，为了保持一致，将中位数放在左边的位置比较好，此时中位数即为：
>
>$$
>max(a[i-1],b[j-1])
>$$

这个时候，我们只需要在$[0,m]$内遍历变量$i$，即可求得结果。

当然，遍历的时间复杂度是$O(m)$，离我们所要求的$O(\log (m+n))$还有差距，所以我们可以使用基于分治思想的二分查找法，即当$a[i-1]>b[j]$时，说明$i$过大，应当向左移动二分之一；当$b[j-1]>a[i]$时，说明$i$过小，应当向右移动二分之一，才能实现对数级的时间复杂度。

接下来加入**边界条件**考虑问题：

主要的边界条件有：

- $m+n$的奇偶问题，当其为奇数时，$res=max(left)$，当为偶数时，$res=(max(left)+min(right))/2$；
- 当$i=0$或者$j=0$时，可以计算$max(left)$，否则$min(right)$也可以计算；
- 当$i=m$或者$j=n$时，可以计算$min(right)$，从而$res=(max(left)+min(right))/2$。

整道题目的代码如下：

```python
class Solution(object):
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        m = len(nums1)
        n = len(nums2)
        if m > n:
            nums1, nums2, m, n = nums2, nums1, n, m

        odd = (m + n) % 2
        start = 0  # 开始元素下标
        end = len(nums1)  # 结束元素下标

        while start <= end:
            i = (start + end) / 2
            j = (m + n + 1) / 2 - i

            if j != 0 and i != m and nums2[j-1] > nums1[i]:
                start = i + 1

            elif i != 0 and j != n and nums1[i-1] > nums2[j]:
                end = i - 1

            else:
                if i == 0:
                    max_left = nums2[j-1]
                elif j == 0:
                    max_left = nums1[i-1]
                else:
                    max_left = max(nums1[i-1], nums2[j-1])
                if odd:
                    return max_left

                if i == m:
                    min_right = nums2[j]
                elif j == n:
                    min_right = nums1[i]
                else:
                    min_right = min(nums1[i], nums2[j])

                return (float(max_left) + min_right) / 2
```

