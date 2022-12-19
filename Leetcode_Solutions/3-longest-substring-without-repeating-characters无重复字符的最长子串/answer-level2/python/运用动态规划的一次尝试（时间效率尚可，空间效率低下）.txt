### 解题思路
尝试用动态规划的思路进行求解，cur用于记录以当前字符结尾的最长子串长度，则新加入一个字符时，有两种情况
    1.新字符不在以前一个字符结尾的最长子串中时，当前字符结尾的最长子串长度加1
    2.否则，查找当前字符在以前一个字符结尾的最长子串中的位置，并计算当前字符的最长子串长度
时刻更新记录中最大子串长度，直到完成遍历整个字符串s，返回ans。
![image.png](https://pic.leetcode-cn.com/8d34c0425230e37be502081a7e26f7b73f9648aee0a55b51a4a005db402d22d9-image.png)


### 代码

```python
class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        if not s:
            return 0
        cur, ans = 1, 1
        for index in range(1, len(s)):
            if s[index] not in s[index-cur:index]:
                cur += 1
            else:
                cur -= s[index-cur:index].index(s[index])
            ans = max(ans, cur)
        return ans
```