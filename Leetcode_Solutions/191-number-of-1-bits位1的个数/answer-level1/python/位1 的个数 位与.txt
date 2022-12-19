### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def hammingWeight(self, n):
        mark = 1
        count = 0
        for i in range(32):
            if (mark & n ) != 0:  #按位与操作，并进行左移
                count += 1
            mark <<= 1
        return count
```