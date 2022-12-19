![捕获.JPG](https://pic.leetcode-cn.com/f34b46484c99bbac8e52d4b4409cd59e2d19626105f512f79d8adba67f8ebd28-%E6%8D%95%E8%8E%B7.JPG)
```
class Solution:
    def findComplement(self, num: int) -> int:
        return num^int(len(bin(num)[2:])*'1',2)
```

