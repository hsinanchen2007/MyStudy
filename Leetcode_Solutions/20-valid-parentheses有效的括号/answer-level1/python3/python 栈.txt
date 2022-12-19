### 解题思路
python用栈作，如果发现右侧括号，那么就去除一对，如果右侧和左侧不匹配，返回False，
最后stack里面所有括号都是成对出现，没有剩余，当stack为空时，返回True

### 代码

```python3
class Solution:
    def isValid(self, s: str) -> bool:
        hashmap={")":"(","}":"{","]":"["}
        stack=[]
        for i in s:
            if i in hashmap:
                if stack:
                    if stack[-1]!=hashmap[i]:
                        return False
                    stack.pop()
            
                else:
                    return False
            else:
                stack.append(i)
        if not stack:
            return True
        return False

```