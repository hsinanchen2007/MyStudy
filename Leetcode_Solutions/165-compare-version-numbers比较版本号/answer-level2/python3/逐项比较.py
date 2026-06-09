逐项转整数比较

```
class Solution:
    def compareVersion(self, version1: str, version2: str) -> int:
        v1 = version1.split('.')
        v2 = version2.split('.')
        l = min(len(v1), len(v2))
        for i in range(l):
            a = v1[i].lstrip('0')
            b = v2[i].lstrip('0')
            if a and b:
                if int(a) > int(b):
                    return 1
                elif int(a) < int(b):
                    return -1
            elif a and not b:
                return 1
            elif not a and b:
                return -1
        if len(v1) > l:
            for i in range(l, len(v1)):
                if v1[i].lstrip('0'):
                    return 1
        elif len(v2) > l:
            for i in range(l, len(v2)):
                if v2[i].lstrip('0'):
                    return -1
        return 0
```