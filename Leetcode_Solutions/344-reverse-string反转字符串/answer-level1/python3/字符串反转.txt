### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def reverseString(self, s: List[str]) -> None:
        """
        Do not return anything, modify s in-place instead.
        """
        
        number= int(len(s)/2)
        for i in range(number):
            a = s[i]
            s[i] = s[len(s)-1-i]
            s[len(s)-1-i] = a
        print(s)
```