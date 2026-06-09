补全0，直接进行比较

```Python
class Solution:
    def compareVersion(self, version1: str, version2: str) -> int:
        v1_list = [int(i) for i in version1.split('.')]
        v2_list = [int(i) for i in version2.split('.')]
        n1 = len(v1_list)
        n2 = len(v2_list)
        if n1 < n2:
            v1_list += [0]*(n2-n1)
        if n1 > n2:
            v2_list += [0]*(n1-n2)
        if v1_list > v2_list:
            return 1
        elif v1_list < v2_list:
            return -1
        else:
            return 0

```
