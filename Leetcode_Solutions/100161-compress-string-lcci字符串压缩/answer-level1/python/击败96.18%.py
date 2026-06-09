### 解题思路
![image.png](https://pic.leetcode-cn.com/8652ab7bfe7395b84b12dd737151a496486ebff834f7c7f72917aa877d6b7bc3-image.png)

### 代码

```python3
class Solution:
    def compressString(self, S: str) -> str:
        size = len(S)
        if size < 2:
            return S
        prev, char_len = S[0], 1
        s, total = prev, 2
        for char in S[1:]:
            if char == prev:
                char_len += 1
            else:  # 遇到新的终止旧的
                total += 2  # 增长两个(最后一位不用处理)
                s += str(char_len) + char
                char_len = 1  # 更新为1
                prev = char  # 更新prev为次轮char
        if total >= size:
            return S
        return s + str(char_len)  # 最后一位数字的处理


```