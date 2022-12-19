### 解题思路
罗马数字中每个字符对应权重是固定的，
但每个字符权重的正负则取决于每个字符和它下一个字符的相对大小

### 代码

```python3
class Solution:
    def romanToInt(self, s: str) -> int:
        val_dict = dict(I=1, V=5, X=10, L=50, C=100, D=500, M=1000)
        val = 0
        length = len(s)
        for i,num in enumerate(s):
            if i == length-1:
                val += val_dict[num]
                break
            if val_dict[num] < val_dict[s[i+1]]:
                val -= val_dict[num]
            else:
                val += val_dict[num]
        return val
            

```