### 解题思路
这一个题目和我之前做 leetcode 的周赛题很相似。

[1352. 最后 K 个数的乘积](https://leetcode-cn.com/problems/product-of-the-last-k-numbers/)  前缀积 pre[i]pre[i] 表示前 ii 个数的乘积即可

也是先做预处理缓存一部分数据，然后直接读数据即可。
但我这一次又想错了，我以为要缓存一个二维数组 nums[i][j] 表示从 i 到 j 的序列和。
但实际上 sum(i, j) = sum(0, j) - sum(0, i-1) 即可。
只需要缓存 sum(0,i) 的所有值。 也就是 一维前缀和


官方代码中在最开头增加了一个虚拟 0， 避免了条件判断。
> 我们插入了一个虚拟 0 作为 sum 数组中的第一个元素。这个技巧可以避免在 sumrange 函数中进行额外的条件检查。


缓存代码没有判断数组长度是否大于 0， 导致出现了一次错误。下标越界。



### 代码

```python3
class NumArray:

    def __init__(self, nums: List[int]):
        self.nums = nums
        n = len(self.nums)
        if n>0:  # 若 n == 0, 可能会导致出错
            self.sumk = [0]*len(self.nums)
            self.sumk[0] = nums[0]
            for i in range(1, len(self.nums)):
                self.sumk[i] = self.sumk[i-1] + self.nums[i]
            
    def sumRange(self, i: int, j: int) -> int:
        if i>j:
            return 0
        else: # i<=j
            if i == 0:
                return self.sumk[j]
            else:
                return self.sumk[j] - self.sumk[i-1]
            
        


# Your NumArray object will be instantiated and called as such:
# obj = NumArray(nums)
# param_1 = obj.sumRange(i,j)
```