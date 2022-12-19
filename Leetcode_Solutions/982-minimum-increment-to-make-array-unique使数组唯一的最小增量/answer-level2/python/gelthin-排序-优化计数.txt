### 解题思路
这一题有点像之前一题，把数组中 n-1 个元素减 1。
[453. 最小移动次数使数组元素相等](https://leetcode-cn.com/problems/minimum-moves-to-equal-array-elements/)

最开始想的思路错误。 
+ 统计最小值x,设 x = 1，然后统计数组中所有落在 [1, n] 之间的数，这部分数必然是可以增加到 1...n. 错误的思路。

后来想到排序：
但写的代码太慢，导致超时。

后来看了官方题解：
+ 解法 1 很巧妙
+ 解法 2 排序，算是常规做法。

### 代码

```python3
class Solution:
    def minIncrementForUnique(self, A: List[int]) -> int:
        n = len(A)
        # 排序法, 超时
        A.sort()
        i = 1
        res = 0
        while i<n:
            if A[i] <= A[i-1]:
                #A[i] += 1  # BUG 太慢
                #res += 1
                res += A[i-1] - A[i] + 1
                A[i] = A[i-1] + 1
            i += 1
        return res


```