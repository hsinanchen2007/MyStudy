### 解题思路
对于每个位置的数num，假设它左边连续的最大子序列和是left_sum, 右边连续最大的子序列和是right_sum, 那么在这个位置最大的子序列和就是left+right, 或者left+right+num, 前者表示移除num，后者表示不移除。

那么问题就变成如何求left_sum, 和right_sum, 要保证它们一个是左边最大连续和，一个是右边最大连续和，所以如果变成负数的话，就可以直接抛弃。
对于left_sum, 可以用一个循环，记录累加和cur，如果cur小于0，设置cur为0，更新left_sum对应位置的值为cur；
对于right_sum, 从右到左，同样的方式求取。
最后再用一个循环，计算每个位置最大的连续子数组和，找出最大的一个。

### 代码

```python3
class Solution:
    def maximumSum(self, arr: List[int]) -> int:
        N = len(arr)
        left, right = [0]*(N+1), [0]*(N+1)
        cur = 0
        for i in range(N):
            cur = max(cur+arr[i], 0)
            left[i+1] = cur
        cur = 0
        for i in range(N)[::-1]:
            cur = max(cur+arr[i], 0)
            right[i] = cur
        
        return max(arr) if max(arr) < 0 else max([max(left[i]+right[i+1], left[i]+arr[i]+right[i+1]) for i in range(N)])

```