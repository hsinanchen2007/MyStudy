### 解题思路

对任意给的首项 a1, 项数n, val = n*a1 + n(n-1)/2, 令 val = target, 遍历 n, 计算 a1 即可
考虑 n 的遍历空间， [2,k], 其中 k 是最后一个使得  k(k+1)/2 <= target 的变量，相当于 1,2,...,k 之和。


### 代码

```python3
class Solution:
    def findContinuousSequence(self, target: int) -> List[List[int]]:
        # 对任意给的首项 a1, 项数n, val = n*a1 + n(n-1)/2, 令 val = target, 遍历 n, 计算 a1 即可
        if target == 1:
            return []
        left, right = 0, target//2
        # 二分搜索 最大的 k s.t. k*(k+1)/2 <= target 相当于 1,...,k 之和为 target,这个 k 也是最大的长度可能
        while left < right:
            mid = (left+right+1)//2
            if mid*(mid+1)/2 > target:
                right = mid-1
            else:
                left = mid
        end = left
        
        result = []
        for n in range(end, 1, -1):  # 至少为2， end 也可取， 为了和示例一致，首先输出较长的序列
            tmp = target - n*(n-1)/2
            if tmp % n == 0:
                a1 = tmp//n
                result.append(list(range(int(a1), int(a1+n))))
        return result

```