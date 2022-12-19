```python
from typing import List
class Solution:
    def validUtf8(self, data: List[int]) -> bool:
        i = 0
        while i < len(data):
            bit_num = '{:08b}'.format(data[i])
            if bit_num[0] == '1':
                cnt = 0
                for j in range(len(bit_num)):
                    if bit_num[j] == '1': cnt = cnt + 1
                    else: break
                if cnt == 1 or cnt > 4: return False
                for j in range(i + 1, i + cnt):
                    if j >= len(data) or '{:08b}'.format(data[j])[:2] != '10': return False
                i = i + cnt
            else:
                i += 1
        return True
```