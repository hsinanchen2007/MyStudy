### 解题思路
去掉开头结尾空白符后，用split按照空白符分割，返回最后一个字符串长度

### 代码

```python3
class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        s_list = s.strip().split(' ')
        return len(s_list[-1])
```
![图片.png](https://pic.leetcode-cn.com/b011c7adff4a3e68b727a83b280af57b24650f563ee886d8e03daaf3ceca2a89-%E5%9B%BE%E7%89%87.png)
