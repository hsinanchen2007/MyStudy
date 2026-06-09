```python
class Solution:	
    def isAdditiveNumber(self, num: str) -> bool:
        # the first segment is significant
        if len(num) < 3: return False
        def judge(s, i, j):
            if j == len(num) : return True
            if j > len(num): return False
            pre, latter = int(num[s:i]), int(num[i:j])
            if len(str(pre)) != len(num[s:i]) or len(num[i:j]) != len(str(latter)): return False
            sum_str = str(pre + latter)
            if sum_str != num[j: j + len(sum_str)]: return False
            return judge(i, j, j + len(sum_str) )

        for i in range(1, len(num)):
            for j in range(i + 1, len(num)):
                if judge(0, i, j):  return True
        return False
```