### 解题思路
1.两者长度差超过1：   False
2.两者长度等于0：
    判断两者不同字符是否等于1或0
3.两者长度等于1：
    判断两者不同字符是否等于1

### 代码

```python3
class Solution:
    def oneEditAway(self, first: str, second: str) -> bool:
        a = len(first)
        b = len(second)
        if abs(a-b) > 1:
            return False
        if a < b:
            first, second = second, first
        count = 0
        for i in range(len(second)): # 判断两者不同字符的位置，如果没有不同返回True
            count = i
            if first[i] != second[i]:
                break
        else: 
            return True
        if a == b: # 两者长度相等，有不同字符，判断剩余count后面字符串时候相同
            return first[count+1:] == second[count+1:]
        else: # 两者长度不相等，有不同字符，判断较长一方的count+1与较短一方的count后面字符串是否相等
            return first[count+1:] == second[count:]

        
            
```