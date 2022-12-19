
![image.png](https://pic.leetcode-cn.com/28886324ed6c100d72d926956d66c20a1538729abb40f184b33c35f8d8f10754-image.png)

LeetCode的编辑器不习惯，在CSDN上写了一份，这里偷懒截图了，想看原地址请戳[CSDN地址](https://blog.csdn.net/LoveHYZH/article/details/92760709)

基本思路就是官方解答那个，我想了好久其他解法没搞定0.0，总是有一种特殊情况很难解决。

![image.png](https://pic.leetcode-cn.com/ec0f123a52e140c06a1f97eca536251a6f9e28342f745540f06c3a5c49854bb6-image.png)
-------------------------------------下面开始具体算法-------------------------------------

![image.png](https://pic.leetcode-cn.com/48da1f498aa4309dad7fc7366688757f6924426a37ae4b92688c78b4b18d97b5-image.png)

![image.png](https://pic.leetcode-cn.com/bcf894d422ebbf9f8aee750b581f0a5d872dd1c544ed43a0e3f39ace2a4ee864-image.png)

![image.png](https://pic.leetcode-cn.com/0d04e3d635614c82bd2bec0cfd030792c5df32da3b76f454921b1c67e2c4439f-image.png)


![image.png](https://pic.leetcode-cn.com/65e04c5157948694376cf28e57c66d9bdf68654c72354a13e946b2fc31dba2b3-image.png)

```python
class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        m, n = len(nums1), len(nums2)

        # 这里为了保证nums1一定是长度较小的数组
        if m > n:
            nums1, nums2, m, n = nums2, nums1, n, m

        # 题目给定数组不会同时为空，也就是m^2+n^2≠0，由于m≤n，故只要n≠0即可
        if not n:
            raise ValueError("数组长度不同时为零")

       	i_min, i_max = 0, m
       
       	# left集合元素数量，如果m+n是奇数，left比right多一个数据
        count_of_left = (m + n + 1) // 2  

        while i_min <= i_max:
            i = (i_min + i_max) // 2  				# left有i个nums1的元素
            j = count_of_left - i  					# left有j个nums2的元素
            if i > 0 and nums1[i - 1] > nums2[j]:
                i_max = i - 1						# i太大，要减少
            elif i < m and nums1[i] < nums2[j - 1]:
                i_min = i + 1						# i太小，要增加
            else:
                if i == 0:
                    max_of_left = nums2[j - 1]
                elif j == 0:
                    max_of_left = nums1[i - 1]
                else:
                    max_of_left = max(nums1[i - 1], nums2[j - 1])

                if (m + n) % 2:
                    return float(max_of_left)				# 结果是浮点数

                if i == m:
                    min_of_right = nums2[j]
                elif j == n:
                    min_of_right = nums1[i]
                else:
                    min_of_right = min(nums1[i], nums2[j])

                return (max_of_left + min_of_right) / 2.0	# 结果为浮点数
```