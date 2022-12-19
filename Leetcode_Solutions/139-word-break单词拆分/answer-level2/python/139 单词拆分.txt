### 解题思路
说到动态回归，大致思路就是：定义一个标记列表 flag，flag[i] 表示到第 i-1 个字符时，是否为能被拆分为字典里的单词。

状态转移矩阵：
flag[j] = flag[i] and s[i:j+1] in wordDict

### 代码

```python
class Solution(object):
    def wordBreak(self, s, wordDict):
        """
        :type s: str
        :type wordDict: List[str]
        :rtype: bool
        """

        flag = [True]+[False]*len(s)

        for start in range(len(s)):
            if flag[start]:
                for end in range(start+1, len(s)+1):
                    if s[start:end] in wordDict:
                        flag[end] = True
        return flag[-1]


```