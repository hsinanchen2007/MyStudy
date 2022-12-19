### 解题思路
`collections.deque`模块实际上已经实现rotate旋转操作接口，旋转参数大于0时右旋，小于0时左旋。注意旋转操作是inplace，无返回值。

### 结果
![image.png](https://pic.leetcode-cn.com/bd6782ad5e290bf81e65a25b35d84e8a056fbcb607891c4970c706082092b7fe-image.png)

### 代码

```python3
class Solution:
    def reverseLeftWords(self, s: str, n: int) -> str:
        s = collections.deque(s)
        s.rotate(-n)
        return ''.join(s)
```