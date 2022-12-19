![image.png](https://pic.leetcode-cn.com/9cb0f6513fd1f73d05a38a064c112adc0949805393143e213ff3dcbe3e271017-image.png)

用字典记录好第一个空格的坐标，减少调用坐标查找函数的次数。

```python []
class Solution:
    def reorderLogFiles(self, logs: List[str]) -> List[str]:
        digs, ltrs, iltrs = [], [], {}
        for log in logs:
            i = log.find(' ') + 1
            if log[i].isdigit():
                digs += [log]
            else:
                iltrs[log] = i
                ltrs += [log]
        return sorted(ltrs, key = lambda log: [log[iltrs[log]: ], log[: iltrs[log]]]) + digs
```
