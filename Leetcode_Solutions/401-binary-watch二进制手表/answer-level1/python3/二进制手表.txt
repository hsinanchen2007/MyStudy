### 解题思路
回溯算法解题=。=

### 代码

```python
class Solution:
    def readBinaryWatch(self, num: int) -> List[str]:
        hour = [1, 2, 4, 8]
        minute = [1, 2, 4, 8, 16, 32]
        result = []

        def backtrack(path, h, m, n):
            # 结束条件
            if len(path) == n:
                if h < 12 and m < 60:
                    if m < 10:
                        times = str(h) + ':0' + str(m)
                    else:
                        times = str(h) + ':' + str(m)
                    result.append(times)
                return
            for i in range(len(hour)+len(minute)):
                if i not in path:
                    if 0 <= i <= 3:
                        h += hour[i]
                        temp = hour[i]
                    elif 4 <= i <= 9:
                        m += minute[i-4]
                        temp = minute[i-4]
                    path.append(i)
                    backtrack(path, h, m, n)
                    path.pop()
                    if 0 <= i <= 3:
                        h -= temp
                    elif 4 <= i <= 9:
                        m -= temp
        backtrack([], 0, 0, num)
        return list(set(result))
```