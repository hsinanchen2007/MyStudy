### 解题思路

按照空白符分开，split()
然后元素反向用空白符join

![image.png](https://pic.leetcode-cn.com/04a0ae712a846fd0f9eb55d4bca8cf686830b7d6cbf67ee7e3f19ac22028c35b-image.png)

### 代码

```python3
class Solution:
    def reverseWords(self, s: str) -> str:
        return  ' '.join(s.split()[::-1])
```