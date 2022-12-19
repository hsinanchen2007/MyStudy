### 解题思路
将int类型转换为二进制字符串直接进行统计即可

### 代码

```python3
class Solution:
    def hammingWeight(self, n: int) -> int:
        n = str(bin(n))
        cnt = 0
        for i in n:
            if i == '1':
                cnt += 1
        return cnt

```