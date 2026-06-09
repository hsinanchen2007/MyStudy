### 解题思路
1. 在name里的每一个字母都会在typed里；
2. 在typed里的每一个字母类型，在name里也有，只不过数量不一样；
3. typed中多按的字母必须是在原先正确的字母后面重复，而不是随意位置；

### 代码

```python3
class Solution:
    def isLongPressedName(self, name: str, typed: str) -> bool:
        charSetN = set(name)
        charSetT = set(typed)
        for item in charSetN:
            if item not in charSetT:
                return False
        for item in charSetT:
            if item not in charSetN:
                return False

        i, j = 0, 0
        while i<len(name) and j<len(typed):
            if name[i] == typed[j]:
                i+=1
                j+=1
            else:
                #: 要么是重复按了
                if j>0 and typed[j]==typed[j-1]:
                    j+=1
                #：要么少按了
                else:
                    return False
        if i==len(name):
            return True
        else:
            return False

# 作者：xdjklxd

        # if len(name) > len(typed):
        #     return False

        # nameC = collections.Counter(name)
        # typedC = collections.Counter(typed)

        # for key1, value1 in nameC.items():
        #     value2 = typedC.get(key1)
        #     if value2 == None:
        #         return False
        #     if value2 < value1:
        #         return False
        #     else:
        #         continue
        # return True
```