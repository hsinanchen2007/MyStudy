
-   直接使用两种匹配模式向后匹配即可
-   模式1保存匹配到符合条件一的，从前方到当前位置的最大长度
-   模式2保存匹配到符合条件二的，从前方到当前位置的最大长度



```python
class Solution:
    def maxTurbulenceSize(self, A: List[int]) -> int:
        pattern1 = 1
        pattern2 = 1
        ans = 1

        for i in range(1, len(A)):
            if i % 2:
                if A[i] < A[i - 1]:
                    pattern1 += 1
                else:
                    pattern1 = 1

                if A[i] > A[i - 1]:
                    pattern2 += 1
                else:
                    pattern2 = 1
            else:
                if A[i] > A[i - 1]:
                    pattern1 += 1
                else:
                    pattern1 = 1

                if A[i] < A[i - 1]:
                    pattern2 += 1
                else:
                    pattern2 = 1

            ans = max(ans, pattern1, pattern2)

        return ans
```


