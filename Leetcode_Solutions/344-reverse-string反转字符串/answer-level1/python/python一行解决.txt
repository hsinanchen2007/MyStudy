### 解题思路
s[:] = s[::-1]

![Snipaste_2020-04-02_14-36-50.png](https://pic.leetcode-cn.com/71ce37939eb812e07c6c6997c4b151be13b6c6715168ae04080404a48853116c-Snipaste_2020-04-02_14-36-50.png)

### 代码

```python3
class Solution:
    def reverseString(self, s: List[str]) -> None:
        """
        Do not return anything, modify s in-place instead.
        """
        s[:] = s[::-1]
```