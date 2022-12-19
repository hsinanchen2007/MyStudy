```python
class Solution:
    def restoreIpAddresses(self, s: str) -> List[str]:
        res = []
        if len(s) < 4 or len(s) > 12: return [] # 排除不可能的情况
        def dfs(temp, restCnt, restStr):
            if restCnt == 0 and restStr == '': # 满足条件
                res.append(temp)
            if len(restStr) < restCnt: return # 当字符串不够时候返回
            for i in range(1, min(3, len(restStr)) + 1):
                if restStr[0] == '0' and i > 1: continue # ip地址首字母为零则只能为1位
                if int(restStr[:i]) <= 255:
                    dfs(temp + ('.' if restCnt != 4 else '') + restStr[:i], restCnt - 1, restStr[i:])
        dfs('', 4, s)
        return res
```
我是渣渣