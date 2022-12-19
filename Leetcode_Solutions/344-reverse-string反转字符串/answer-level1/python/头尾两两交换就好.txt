### 解题思路
此处撰写解题思路
   头尾两两交换就好了

### 代码

```python3
class Solution:
    def reverseString(self, s: List[str]) -> None:
        """
        Do not return anything, modify s in-place instead.
        """
        l=len(s)
        middle=int(l/2)
        for i in range(0,middle):
            s[i],s[l-1-i]=s[l-1-i],s[i]

        
```