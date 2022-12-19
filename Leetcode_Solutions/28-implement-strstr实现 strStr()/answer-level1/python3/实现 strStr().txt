### 解题思路
![leetcode28.png](https://pic.leetcode-cn.com/c916ae460faebb82f0649bffa0744438b139ccab7f260087cb5e96f91cc69387-leetcode28.png)


1.先判断needle是否为空或者两个字符串是否相等，满足条件返回0
2.遍历字符串haystack
3.判断haystack哪个元素开始等于needle，有则返回第一个元素在haystack的位置，没有返回-1

### 代码

```python3
class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        if needle == "" or needle == haystack:#先判断needle是否为空或者两个字符串是否相等，满足条件返回0
            return 0
        for i in range(len(haystack)):#遍历字符串haystack
            if (i+len(needle)) <= len(haystack) and haystack[i:(i+len(needle))] == needle:#判断haystack哪个元素开始等于needle，有则返回第一个元素在haystack的位置，没有返回-1
                return i
            else:
                continue
        return -1
```