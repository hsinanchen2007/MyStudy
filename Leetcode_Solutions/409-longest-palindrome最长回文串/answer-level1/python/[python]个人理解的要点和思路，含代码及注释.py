```python
class Solution:
    def longestPalindrome(self, s: str) -> int:
        """
        要点：
        在回文字符串中，至多只有一个字符的出现次数为奇数
        
        思路：
        统计每个字符的个数，再对这些字符的出现次数进行遍历
        每个字符出现次数为偶数的字符,可以使长度增加其出现次数
        出现次数为奇数的字符,可以使长度增加其出现次数-1
        第一次遇到次数为奇数的，将整体长度+1（即将这个字符作为回文中心）
        """
        nums = collections.Counter(s)  # 统计每个字符的出现次数，并赋值为字典
        res = 0
        flag = True
        for value in nums.values():  # 忽略字符本身，只分析字符的出现次数
            res += value // 2 * 2  # 每次增加字符出现次数的最小偶数
            if flag and value % 2 == 1:  # 第一次遇到次数为奇数的，将整体长度+1
                res += 1
                flag = False
        
        return res

```
