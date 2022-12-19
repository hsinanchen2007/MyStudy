python语言：
这里只考虑去重后数组长度还大于三的情况
使用堆数据结构，维护一个数量为3的小顶堆，先把前三个数建成一个小顶堆，然后从第三个数开始然后循环数组，遇到比堆顶更大的数就加进去替换堆顶，然后进行堆维护保持堆是一个小顶堆，循环完后将堆顶得数返回即可
代码如下，
(我这里就偷懒了，直接使用heapq模块了)
```
def thirdMax(self, nums: List[int]) -> int:
    nums = list(set(nums))
    from heapq import nlargest
    return max(nums) if len(nums)<3 else nlargest(3, nums)[2]
```

