### 解题思路


### 代码
![微信图片_20200315150847.png](https://pic.leetcode-cn.com/3feffe64e0b5543ec0bff2afff8218d3f4f30be3c54061e35f81bed91780b2a6-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20200315150847.png)
```python3
class Solution:
    def reverseString(self, s: List[str]) -> None:
        """
        Do not return anything, modify s in-place instead.
        """
        low=0
        high=len(s)-1
        while low<high:
            temp=s[low]
            s[low]=s[high]
            s[high]=temp
            low+=1
            high-=1
        
```