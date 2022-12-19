### 解题思路
一共三步：
1.以小数点"."分割字符串。
2.将短列表填充，使两个列表一样长。
3.将两个等长的字符串列表进行比较。
### 代码

```python3
class Solution:
    def compareVersion(self, version1: str, version2: str) -> int:
        #切割
        list1 = version1.split(".")
        list2 = version2.split(".")
        #填充
        if len(list1) > len(list2):
            list2 += ['0'] * (len(list1) - len(list2))
        elif len(list1) < len(list2):
            list1+=['0'] * (len(list2) - len(list1))
        #比较
        i = 0
        while i < len(list1) and i < len(list2):
            if int(list1[i]) > int(list2[i]):
                return 1
            elif int(list1[i]) < int(list2[i]):
                return -1
            i += 1
        return 0 
```