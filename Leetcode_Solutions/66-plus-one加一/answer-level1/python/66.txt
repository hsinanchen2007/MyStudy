### 解题思路
1、处理特殊情况：个位数=9，9+1=10，个位数<9，直接+1。
2、倒序遍历list：
2.1、处理下标1~n-1：小于9，直接+1返回digits；等于9需要进位，9变成0，进入下次循环。
2.2、处理下标0：等于9则list前加1，9改为0。

### 代码

```python3
class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        if len(digits) == 1 and digits[0] == 9:
            return [1, 0]
        if len(digits) == 1 and digits[0] < 9:
            return [digits[0]+1]
        for i in range(len(digits)-1, -1, -1):
            if i > 0:
                if digits[i] < 9:
                    temp = digits[i]
                    digits[i] = temp + 1
                    return digits
                elif digits[i] == 9:
                    digits[i] = 0
            if i == 0:
                if digits[i] == 9:
                    digits[i] = 0
                    digits.insert(0, 1)
                    return digits
                else:
                    temp = digits[i]
                    digits[i] = temp + 1
                    return digits
```