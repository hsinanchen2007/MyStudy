### 解题思路
![QQ截图20200216150705.png](https://pic.leetcode-cn.com/58761a45d47db1bf7b7226aa6158591de8b1367875617e28fdd0320c142f4998-QQ%E6%88%AA%E5%9B%BE20200216150705.png)


### 代码

```python3
class Solution:
    def hasAlternatingBits(self, n: int) -> bool:
        bin_n=bin(n)
        if bin_n.find("11")==-1 and bin_n.find("00")==-1:
            return True
        else:
            return False
```