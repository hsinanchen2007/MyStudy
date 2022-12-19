```python
class Solution:
    def hammingWeight(self, n: int) -> int:
        cnt = 0
        while n > 0:
            if n%2:
                cnt += 1
            n >>= 1
        return cnt
```

输入数据解析不出来
![image.png](https://pic.leetcode-cn.com/beab4c9253057b462f620eda09939364923f0a0554f856209e18f740a52de625-image.png)
