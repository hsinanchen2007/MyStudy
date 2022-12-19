### 解题思路
![截图.PNG](https://pic.leetcode-cn.com/0f545eeb4b55b9cd8c6d82e094d47cfa78381d3b05877cda1d748e6ee6123081-%E6%88%AA%E5%9B%BE.PNG)

分析规律得：结果序列长度len为偶数时，平均值的小数部分是0.5；len为奇数时，平均值是整数。
思路：target依次除以2、3...limit后求小数部分得到temp，1累加到limit = target（减少冗余计算）
     如果temp==0.5且i为偶数，或者temp==0且i为奇数，那么i就是有效的len。

### 代码

```python3
class Solution:
    def findContinuousSequence(self, target: int) -> List[List[int]]:
        if target < 3:
            return []
        limit = int(((target * 2 + 0.25) ** 0.5 - 0.5) // 1)
        result = []
        for i in range(limit, 1, -1):
            temp = target / i % 1
            if (i & 1 == 0 and temp == 0.5) or (i & 1 != 0 and temp == 0):
                base = target // i - i // 2 + temp * 2
                one_result = [0] * i
                for j in range(i):
                    one_result[j] = int(base + j)
                result.append(one_result)
        return result
```