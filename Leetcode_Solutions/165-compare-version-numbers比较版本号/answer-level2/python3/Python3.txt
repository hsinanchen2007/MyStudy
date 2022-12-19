### 解题思路
难在写判断条件
![2019-12-06 23-50-34屏幕截图.png](https://pic.leetcode-cn.com/3f2367e1e48006535ff3cb813c0db825d788225e80daf82da080d7b9be8c793a-2019-12-06%2023-50-34%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE.png)


### 代码

```python3
class Solution:
    def compareVersion(self, version1: str, version2: str) -> int:
        l1 = version1.split('.')
        l2 = version2.split('.')
        if len(l1) > 1:
            for i in range(1,len(l1)):
                if l1[i].lstrip('0'):
                    l1[i] = l1[i].lstrip('0')
        if len(l2) > 1:
            for i in range(1,len(l2)):
                if l2[i].lstrip('0'):
                    l2[i] = l2[i].lstrip('0')
        l1 = list(filter(None, l1))
        l2 = list(filter(None, l2))
        if len(l1) < len(l2):
            for i in range(len(l2) - len(l1)):
                l1.append('0')
        else:
            for i in range(len(l1) - len(l2)):
                l2.append('0')
        for i in range(len(l1)):
            if int(l1[i]) > int(l2[i]):
                return 1
            elif int(l1[i]) < int(l2[i]):
                return -1
        return 0
```