### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def hammingWeight(self, n: int) -> int:
        # nStr = str(n)
        # countOne = 0
        # for i in range(len(nStr)):
        #     if nStr[i] == '1':
        #         countOne += 1
        #         print(countOne)
        # return countOne
        binN = bin(n)
        return str(binN).count('1')
```