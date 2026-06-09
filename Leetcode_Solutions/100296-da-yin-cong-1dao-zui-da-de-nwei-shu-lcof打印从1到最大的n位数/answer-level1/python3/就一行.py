### 解题思路
此处撰写解题思路
直接利用10的n次幂
![批注 2020-02-23 213128.jpg](https://pic.leetcode-cn.com/3cf27db115c9d824a2207c0a7c08ffd21e4a42e44e340158ecc5548f7d5e3c30-%E6%89%B9%E6%B3%A8%202020-02-23%20213128.jpg)

### 代码
```python3
class Solution:
    def printNumbers(self, n: int) -> List[int]:
        return [x for x in range(1,10**n)]
```
