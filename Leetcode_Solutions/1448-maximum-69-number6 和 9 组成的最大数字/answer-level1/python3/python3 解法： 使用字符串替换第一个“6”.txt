### 运行结果
![捕获.PNG](https://pic.leetcode-cn.com/8f95e1a0806e249e0e994886c8272ba25ce5b8aec262ae1c8eebf6c8402bbfd5-%E6%8D%95%E8%8E%B7.PNG)

### 解题思路
使用字符串替换第一个“6”

### 代码

```python3
class Solution:
    def maximum69Number (self, num: int) -> int:
        return int(str(num).replace('6', '9', 1))
```