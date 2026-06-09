### 解题思路
遍历数组，讲数字转化为字符串，通过%2==0算出长度是否为偶数

### 代码

```python3
class Solution:
    def findNumbers(self, nums: List[int]) -> int:
        sum = 0;
        for i in nums:
            if len(str(i)) % 2 == 0:
                sum +=1
        return sum
```