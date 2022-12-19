### 解题思路
![绘图1.jpg](https://pic.leetcode-cn.com/29bb4a5e78299a7e8c8ce8c9d98c0fe22d39b1df0ab1715790e5be51e0ddb522-%E7%BB%98%E5%9B%BE1.jpg)

1. 当窗口中没有该字符加入即可
2. 用position控制窗口的起始位置，保证不会使得窗口从左边扩大，例如加入第二个A后，第一个A的位置小于B，所以向后滑动。更新字典中字符串的位置信息

### 代码

```python3
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if not s: return 0
        dic = {}
### total 表示无重复字符的长度   position表示窗口的开始截断点
        total,position = 0,0
        for i, val in enumerate(s):
            if not val in dic:
                dic[val] = i+1
            else:
                #发现重复的字符，比较最新的截断点和之前的截断点哪一个位置更大
                #也就是说哪里取到的窗口最小
                position = max(dic[val], position)
                #记录重复字符串的新位置
                dic[val] = i + 1
            #取表示无重复字符的长度最长
            total = max(i + 1 - position, total)
        return total


```