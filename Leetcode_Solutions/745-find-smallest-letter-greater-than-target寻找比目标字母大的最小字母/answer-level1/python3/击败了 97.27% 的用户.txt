### 解题思路
看下每个字母是否在letters中

### 代码

```python3
class Solution:
    def nextGreatestLetter(self, letters: List[str], target: str) -> str:
        for i in range(1,26):
            ans = chr(97+(ord(target)+i-97)%26) 
            if ans in letters:
                return ans

```