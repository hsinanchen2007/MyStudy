### 解题思路
哈夫曼编码无歧义，直接从左往右读即可，根据最后游标所在的位置，判断最后一位是否是0

### 代码

```python3
class Solution:
    def isOneBitCharacter(self, bits: List[int]) -> bool:
        length = len(bits)
        i = 0
        while i != length-1 and i != length:
            if bits[i] == 1:
                i += 2
            elif bits[i] == 0:
                i += 1
        if i == length-1:
            return True
        return False
        
            
```