### 解题思路


### 代码

```python3
class Solution:
    def isLongPressedName(self, name: str, typed: str) -> bool:
        typed_index, name_index = 0, 0

        for i in range(len(typed)):
            if name_index == len(name) - 1 and name[name_index] == typed[i]:
                return True
            if typed[i] == name[name_index]:
                print(typed[i])
                name_index += 1
        
        return False

```