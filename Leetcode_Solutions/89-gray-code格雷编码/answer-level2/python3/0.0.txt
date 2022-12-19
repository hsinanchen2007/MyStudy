### 解题思路
格雷码的生成：
G(i)=i xor (i/2)

### 代码

```python3
class Solution:
    def grayCode(self, n: int) -> List[int]:
        ans=[0]
        for i in range(1,2**n):
            ans.append((i) ^ (int(i/2)))
        return ans
```