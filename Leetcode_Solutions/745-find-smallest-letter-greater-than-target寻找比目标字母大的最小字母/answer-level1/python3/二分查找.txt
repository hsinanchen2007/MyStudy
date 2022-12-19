1. 判空处理
2. 找到 target 的右边的值
3. 超过数组范围返回第一个值

``` python
class Solution:
    def nextGreatestLetter(self, letters: List[str], target: str) -> str:
        if not letters:
            return ''
        l, r = 0, len(letters)
        
        while l < r:
            m = (l+r) // 2
            if letters[m] > target:
                r = m
            else:
                l = m+1
        return letters[l] if l < len(letters) else letters[0]
```
