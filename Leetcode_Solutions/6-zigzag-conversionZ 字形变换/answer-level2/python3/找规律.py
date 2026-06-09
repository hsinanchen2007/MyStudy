### 解题思路
通过数学关系，确定zigzag的位置
时间复杂度$O(n)$ 空间复杂度$O(n)$
![eee753f998b4cef03321d43f5d93cd2.jpg](https://pic.leetcode-cn.com/fc954a31d52303c395ec0c9df7736466b16c1b6ed817e3caef5979f31a52308f-eee753f998b4cef03321d43f5d93cd2.jpg)

### 代码

```python3
class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows <= 1:
            return s
        s_array = ['' for _ in range(numRows)]
        zigzag = ''
        for i,c in enumerate(s):
            i = i % ((numRows-1)*2)
            if i < numRows:
                s_array[i] += c
            else:
                i = (numRows-1)*2 - i
                s_array[i] += c
    
        for substr in s_array:
            zigzag += substr
        
        return zigzag
```