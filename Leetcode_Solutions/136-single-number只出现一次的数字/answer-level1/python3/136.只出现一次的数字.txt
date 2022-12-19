### 解题思路
看了官方题解，抑或很牛逼哦
疑惑本身等于0，抑或0等于本身

### 代码

```python3
class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        a = 0
        for i in nums:
            #抑或
            a ^= i
        return a

```