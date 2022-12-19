### 代码

```python3
class Solution:
    def isValid(self, s: str) -> bool:
        hash = {-1:'(',1:')',-2:'[',2:']',-3:'{',3:'}'}
        length = len(s)
        if length == 0:
            return True

        if length % 2 != 0:
            return False

        ls = []

        for i in range(0,length):
            for key in hash:
                if hash[key] == s[i] and key < 0:
                    ls.append(key)
                    break
                if hash[key] == s[i] and key > 0:
                    # 寻找它对应的-key,
                    # 但是如果途中遇到不配对的但是小于0的return false,
                    # 如果找到最后都没找到配对的，return false
                    # 如果找到了，把它配对的那个key从list中删除
                    j = len(ls) - 1
                    while j >= 0:
                        if ls[j] + key != 0 and ls[j] < 0:
                            return False
                        elif ls[j] + key == 0:
                            ls.pop(j)
                            break
                        else:
                            j -= 1

                    if j < 0:
                        return False

                    break

        if len(ls) == 0:
            return True
        else:
            return False
```