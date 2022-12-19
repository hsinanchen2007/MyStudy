思路用的是这个：[https://leetcode-cn.com/problems/max-consecutive-ones-iii/solution/hua-dong-chuang-kou-de-chang-gui-jie-fa-by-xiaonen/]
感谢大佬！[@xiaoneng](/u/xiaoneng/)


```python []
class Solution:
    def longestOnes(self, A: List[int], K: int) -> int:
        result = 0
        left = right = 0
        count = 0
        if K >= len(A): #题里面有个特殊case是[0,0,0,1]，返回4
            return K

        while right < len(A):
            if A[right] == 0:
                count += 1
            while count > K:
                if A[left] == 0:
                    count -= 1
                left += 1
            result = max(result, right - left + 1)
            right += 1
        return result
```
