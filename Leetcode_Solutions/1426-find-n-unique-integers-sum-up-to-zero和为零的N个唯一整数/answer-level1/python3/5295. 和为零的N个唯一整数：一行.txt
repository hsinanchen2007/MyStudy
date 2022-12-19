### 解题思路
折半反而麻烦，从`1-n`开始隔一个输出一个比较简单。

### 代码

```python []
class Solution:
    def sumZero(self, n: int) -> List[int]:
        return range(1 - n, n, 2)
```

![image.png](https://pic.leetcode-cn.com/f7e449b7f967971e8396774492bc5093e977fd261f59b69b7efbf2ef19ce21e7-image.png)
