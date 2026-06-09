1、冒泡排序(超时)

- 索引i从0开始，一直到nums的倒数第二个数；
- 每次遍历nums的i及i之后的部分，称为一趟；
- 如果是升序排列，每一趟，把遍历部分的最小的数移动到nums[i]；
- 如果是降序排列，每一趟，把遍历部分的最大的数移动到nums[i]；

Python代码如下：

```python
class Solution:
    def sortArray(self, nums: List[int]) -> List[int]:
        # 冒泡排序
        for i in range(len(nums) - 1):
            # 每一次把nums[i:]这部分的最小的数，移动到nums[i]
            for j in range(len(nums) - 1, i, -1):
                if nums[j] < nums[j - 1]: # 降序就是>
                    nums[j], nums[j - 1] = nums[j - 1], nums[j]
        return nums
```

复杂度分析

- 空间复杂度，没有新开数组，直接对原数组进行修改，所以为O(1)
- 时间复杂度，O(n^2)

2、快速排序

快排的思想，是把待排序的序列分为两部分，其中前一部分的数据比后一部分的都要小，然后再递归调用函数，对这两部分数据分别进行快速排序，从而使得整个序列有序。那么如何将数组分为大小两部分呢？可以从数组中选择一个元素作为标杆，可以是随机选，也可以选第一个或最后一个元素，比这个标杆小的，就划分到左边，否则就划分到右边。

Python代码如下：

```python
class Solution:
    def sortArray(self, nums: List[int]) -> List[int]:
        # 快速排序
        if len(nums) == 0 or len(nums) == 1:
            return nums
        # 默认选择第0个数作为判断大小的标杆
        # 比标杆小的，放在left，其他的放在right。
        left, right = [], []
        for i in range(1, len(nums)):
            if nums[i] < nums[0]:
                left.append(nums[i])
            else:
                right.append(nums[i])
        # 标杆放在较短的一部分或者左边
        # 比如放在右边，假设对[2,3]排序，那么，拆分后，左边为[]，右边还是[2,3]
        left.append(nums[0])
        left, right = self.sortArray(left), self.sortArray(right)
        return left + right
```

复杂度分析

- 空间复杂度：取决于递归的深度
- 时间复杂度：O(nlogn)

3、归并排序

和快排一样，都用到了分治的思想， 不同的是，归并排序，是将数组分成长度相同的两部分，分别对两部分排序，然后将有序的两部分进行线性归并。

线性归并的过程，就是用i和j代表左右两个部分，也就是left和right的索引，从0开始增加，如果left[i]小一些，就把left[i]添加到结果res的最后，并且i++；否则，就把right[j]添加到结果res的最后，并且j++。如果I,j有一个增加到了对应部分的长度，停止循环，并将没有达到的那一部分剩下没有遍历的元素全部依次添加到res的最后。

Python代码：

```python
class Solution:
    def sortArray(self, nums: List[int]) -> List[int]:
        # 归并排序
        if len(nums) == 0 or len(nums) == 1:
            return nums
        # 计算中间索引
        mid = len(nums) // 2
        # 对左右部分分别进行排序
        left = self.sortArray(nums[:mid])
        right = self.sortArray(nums[mid:])
        # 对排序的两个部分进行线性归并
        i = j = 0
        res = []
        while i < len(left) and j < len(right):
            if left[i] < right[j]:
                res.append(left[i])
                i += 1
            else:
                res.append(right[j])
                j += 1
        if i == len(left): res += right[j:]
        if j == len(right): res += left[i:]
        return res
```

复杂度分析：

- 时间复杂度：O(nlogn)，同时与递归的深度也有关
- 空间复杂度：主要是开了res数组，存储线性归并的结果，所以是O(n)