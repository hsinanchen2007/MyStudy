### 解题思路
第一次的题解使用暴力方法，全部枚举一遍，没有利用到有序的特性。

这次的题解，参考了官方题解，利用行有序的条件，对每一行使用二分搜索，搜索出第一个 <0 的数的下标，然后累加即可。只是注意到由于不一定能够搜索到目标，因此一定要 check 一下。
但仅仅这样，没有利用到列有序的条件。实际上，列有序的条件可以用来减少接下来的行的搜索空间。
为了更好控制，可以对 List 进行反序，先计算最后一行，设最后一行计算出来的为t, 则倒数第二行的搜索空间为 [t, n-1]。




### 代码

```python3
class Solution:
    def countNegatives(self, grid: List[List[int]]) -> int:
        # 多个二分
        _, n = len(grid), len(grid[0])
        result = 0
        search_init = 0
        for x in grid[::-1]: #为了更好利用列有序，将 grid 反序
            # 查找第一个 <0 的数的下标，利用行有序的条件
            a, b = search_init, n-1   # 利用列有序的条件，可以优化搜索空间
            while a<b:
                mid = a + (b-a)//2
                if x[mid] >= 0:
                    a = mid+1
                else:
                    b = mid
            if x[a] < 0: # 由于不一定存在负数，这里一定要测试一下
                result += n-a
                search_init = a
            else:
                break  # 直接结束，后面也不用搜索了
        return result
```