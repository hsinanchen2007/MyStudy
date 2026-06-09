1. 先转成list
2. 再去掉末尾的0 利用while和pop
3. 遍历比较
4. 超出短list长度，余下哪个多就是哪个大，不然就是相等

```
class Solution:
    def compareVersion(self, version1: str, version2: str) -> int:
        v1 = [int(item) for item in version1.split('.')]
        v2 = [int(item) for item in version2.split('.')]
        # 去掉末尾的0
        while len(v1) > 1 and v1[-1] == 0: v1.pop()
        while len(v2) > 1 and v2[-1] == 0: v2.pop()
        index = 0
        while index < min(len(v1), len(v2)):
            if v1[index] > v2[index]: return 1
            elif v1[index] < v2[index]: return -1
            else: index += 1
        # 短list遍历结束后再次比较
        if len(v1) > len(v2): return 1
        elif len(v1) < len(v2): return -1
        else: return 0
```

