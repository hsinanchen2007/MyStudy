### 解题思路
从倒数第二位起，算连续1的个数
只有连续1的个数为偶数，才能保证最后一位一定是1比特

### 代码

```python3
class Solution:
    def isOneBitCharacter(self, bits: List[int]) -> bool:
        tmp = 0
        for i in range(len(bits)-2,-1,-1):
            if bits[i] != 1:
                break
            else:
                tmp += 1
        if tmp % 2 == 0:
            return True
        return False
```