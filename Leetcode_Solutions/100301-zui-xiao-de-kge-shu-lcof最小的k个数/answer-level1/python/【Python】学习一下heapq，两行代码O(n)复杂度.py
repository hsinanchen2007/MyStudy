
其实按照题意，这个应该是要做流式处理的。`arr`不应该是个列表（或其它语言的数组），而应该是个生成器（或其它语言的stream）。
但既然已经是个列表了，排个序就行。

## 简单排序，一行代码

```python
class Solution:
    def getLeastNumbers(self, arr: List[int], k: int) -> List[int]:
        return sorted(arr)[:k]
```

这个算法胜在简单有效，败在时间和空间复杂度都很高。

> 执行用时 : `76 ms`, 在所有 Python3 提交中击败了`74.73%`的用户
> 内存消耗 : `14.5 MB`, 在所有 Python3 提交中击败了`100.00%`的用户

## 简单排序，两行代码

```python
class Solution:
    def getLeastNumbers(self, arr: List[int], k: int) -> List[int]:
        arr.sort()
        return arr[:k]
```

这样写，省去了由`sorted`生成的一个额外列表的开销，但是排序的时间复杂度省不了。
两个排序大概都是`O(nlog(n))`的时间复杂度。

> 执行用时 : `60 ms`, 在所有 Python3 提交中击败了`88.35%`的用户
> 内存消耗 : `14.4 MB`, 在所有 Python3 提交中击败了`100.00%`的用户

## heapq方案

```python
class Solution:
    def getLeastNumbers(self, arr: List[int], k: int) -> List[int]:
        heapq.heapify(arr)
        return heapq.nsmallest(k, arr)
```

`heapq.heapify`是在当前列表进行原地建堆，只消耗`O(n)`的时间复杂度，是理论上本题的Python最优解。
自实现的标准答案，理论极限也大概就这样的。

> 执行用时 : `124 ms`, 在所有 Python3 提交中击败了`57.67%`的用户
> 内存消耗 : `15.1 MB`, 在所有 Python3 提交中击败了`100.00%`的用户

## 结论

所以，Python的理论值，有时候是没有用的。
按道理不应该是一个比一个快吗？！
说好的线性时间复杂度呢？！

另外，leetcode也是，“执行用时”飘，也就忍了。
虚拟化、容器化的计算节点，不稳定也是正常的。
这个“内存消耗”是怎么回事？

`14.5 MB`击败了`100.00%`。我不知道，就随你说吧。

`14.4 MB`击败了`100.00%`。好吧，看来我额外的`O(n)`空间复杂度没白省。

`15.1 MB`击败了`100.00%`？！我是按顺序跑的啊，刚才那两个结果被吃了？而且一个`in-place`的算法，是怎么输给第一个的？

但无论如何，`heapq`值得学习一下。