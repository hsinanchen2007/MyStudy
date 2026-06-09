### 运行结果

![image.png](https://pic.leetcode-cn.com/26d6220ab32b56df55a34d3069a0f54b5997ed2272c05dfedc2c657904932673-image.png)

### 解题思路

不重复造轮子，一行搞定

### 代码

```python3
class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        return os.path.commonprefix(strs)
```