### 解题思路
# 一对一对取出，如果是单着的，选一个就行
def longestPalindrome1_2(self, s):
    s_list = list(s)
    res, odd = 0, 0
    while s_list:
        c = s_list.pop()              # 弹出最后一个元素
        if c in s_list:               # 最后一个元素出现在剩下的元素中
            s_list.remove(c)          # 删除相同的，相当于同时删除了一对
            res += 2                  # 长度加2
        else:
            odd = 1                   # 选一个奇数的放中间
    return res + odd

### 代码

```python
class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: int
        """
        s_list = list(s)
        res,odd = 0,0
        while s_list:
            c = s_list.pop()
            if c in s_list:
                s_list.remove(c)
                res +=2
            else:
                odd = 1
        return res + odd
```