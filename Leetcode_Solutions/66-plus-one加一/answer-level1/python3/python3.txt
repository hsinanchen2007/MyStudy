![Jietu20191202-225433.jpg](https://pic.leetcode-cn.com/fb8e52ef344226096bce5e7b19bf3fc0b06726fd8fa8c3c615d08afe28c51583-Jietu20191202-225433.jpg)

取个巧，用下python自带的函数。

```
class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        return [int(i) for i in list(str(int(''.join([str(i) for i in digits]))+1))]
```
