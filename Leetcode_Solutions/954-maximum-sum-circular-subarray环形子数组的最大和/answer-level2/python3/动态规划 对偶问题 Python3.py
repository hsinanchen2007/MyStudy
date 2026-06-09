**思路：**

两个思路：一种是将数组复制一份，拼接在原数组后边，用求连续子数组最大和的方法求解，求解过程中需要用一个队列来控制子数组长度不超过原数组的长度；另一种方法更为巧妙，将结果分为两种可能的情况，一种是不跨边界的情况直接求解，一种是跨边界则将问题转化为求解不跨边界的子数组和最小，再用原数组求和减去这个最小值则为最大值，此种方法需要考虑数组中元素全为负数的情况。

时间复杂度$O(N)$

空间复杂度$O(N)$

**代码：**

解法1

```python
class Solution:
    def maxSubarraySumCircular(self, A: List[int]) -> int:
        l = len(A)
        A = A + A
        ans = A[0]
        s = [0] * (2 * l)
        q = [0]
        for i in range(1, 2 * l):
            s[i] = s[i - 1] + A[i - 1]
            while q and q[0] < i - l:
                q.pop(0)
            ans = max(ans, s[i] - s[q[0]])
            while q and s[q[-1]] > s[i]:
                q.pop()
            q.append(i)
        return ans
```

解法2

```python
class Solution:
    def maxSubarraySumCircular(self, A: List[int]) -> int:
        result = 0
        curr_max = 0
        result_max = 0
        
        # 分两种情况
        # 一种为没有跨越边界的情况，一种为跨越边界的情况 没有跨越边界的情况直接求子数组的最大和即可
        for num in A:
            curr_max += num
            if curr_max <= 0:
                curr_max = 0
            if curr_max > result_max:
                result_max = curr_max
                
        # 考虑全部为负数的情况
        if result_max == 0:
            result = max(A)
            return result
        
        # 跨越边界的情况可以对数组求和再减去无环的子数组的最小和，即可得到跨越边界情况下的子数组最大和
        curr_min = 0
        result_min = 0
        for num in A:
            curr_min += num
            if curr_min >= 0:
                curr_min = 0
            if curr_min < result_min:
                result_min = curr_min
        
        result = max(result_max, sum(A)-result_min)
        
        return result
```