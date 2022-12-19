这个问题被称为荷兰国旗问题，是 Dijkstra 提出的（求非负权值图上的单源最短路径的 Dijkstra 算法、预防死锁的银行家算法也是他提出来的）。

荷兰国旗有三种颜色，这道题目就是要给只有 0, 1, 2 三种数字的数组排序。

## 方法一：两次遍历，统计个数 + 生成新数字
两次遍历的方法比较简单，第一次遍历先统计出每个数字出现的次数，下一次遍历直接按照次数生成新数字就可以了，完全不用交换数字。

```python
class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        cnt = [0] * 3
        for n in nums: cnt[n] += 1
        i = 0
        for cur in range(3):
            for j in range(cnt[cur]):
                nums[i] = cur
                i += 1
```

这个方法很清晰


## 方法一：一次遍历，三指针
l 指向 0 的右边，r 指向 2 的最左边，cur 则是当前查看的数字。

如果当前的数字是 0，就交换给 l，如果是 2 则交换给 r。如果是 1 就不用动了。

但是这里和 l 交换与和 r 交换不同的是，与 l 交换后 cur 加一以跳过刚从前面换过来的数组，但是与 r 交换不行，这是因为与 l 交换来的数，都是前面过来的，**一定是 1**,所以不用再看。


```python
class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        l = cur = 0
        r = len(nums) - 1
        while cur <= r:
            if nums[cur] == 0:
                if cur != l:
                    nums[cur], nums[l] = nums[l], nums[cur]
                cur += 1
                l += 1
            elif nums[cur] == 2:
                nums[cur], nums[r] = nums[r], nums[cur]
                r -= 1
            else:
                cur += 1
```

欢迎来我的博客： [https://codeplot.top/](https://codeplot.top/)
我的博客刷题分类：[https://codeplot.top/categories/%E5%88%B7%E9%A2%98/](https://codeplot.top/categories/%E5%88%B7%E9%A2%98/)