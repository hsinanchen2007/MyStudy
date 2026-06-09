### 解题思路
此处撰写解题思路
返回时候直接返回 `letterLog + digitLog`反而比将其赋值给`logs`再返回时间增加，消耗内存也增加！！！
### 代码

```python
class Solution(object):
    def reorderLogFiles(self, logs):
        """
        :type logs: List[str]
        :rtype: List[str]
        """
        digitLog = []
        letterLog = []
        for s in logs:
            if s.split(" ")[1][0].isdigit():
                digitLog.append(s)
            if  s.split(" ")[1][0].isalpha():
                letterLog.append(s)
        letterLog = sorted(letterLog,key=lambda s:s.split(" ")[0])
        letterLog = sorted(letterLog,key=lambda s:" ".join(s.split(" ")[1:]))
        logs = letterLog + digitLog 
        return logs
```