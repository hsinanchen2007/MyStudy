#### 解题思路：
本题采用了两种方法，即回溯法和动态规划法，但效果天差地别。

**方法一:回溯法**

于本题而言，无非就是从给定字符串 s 的第一个字符开始遍历，如果截取的子串刚好出现在 wordDict 中，那么接着该子串的位置继续往后遍历，重复同样操作，如果最后字符串 s 分割成的几个子串刚好都出现在 wordDict 中，那么输出 True，反之输出 False。这也就是回溯的思想，其实很 easy!

代码如下：
```Python [-Python]
class Solution(object):
    # 回溯法
    def wordBreak(self, s, wordDict):
        """
        :type s: str
        :type wordDict: List[str]
        :rtype: bool
        """
        def back(start=0, flag=False):
            if start >= len(s):
                return True
            for end in range(start, len(s)):
                sub_str = s[start:end+1]
                if sub_str in wordDict:
                    flag = back(end+1)
                    if flag is True:
                        return True
            return False
        return back()

if __name__ == "__main__":
    s = "aaaaaaa"
    wordDict = ["aaaa","aaa"]
    flag = Solution().wordBreak(s, wordDict)
    print(flag)
```
但是超出时间限制了！没办法，效率不行，只能试试动态回归算法了。

**方法二：动态规划法**

说到动态回归，大致思路就是：定义一个标记列表 `flag`，`flag[i]` 表示到第 `i-1` 个字符时，是否为能被拆分为字典里的单词。

**状态转移矩阵**：
`flag[j] = flag[i] and s[i:j+1] in wordDict`

代码如下：

```Python [-Python]
class Solution(object):
    # 本题回溯法超出时间限制，采用动态回归法
    def wordBreak(self, s, wordDict):
        """
        :type s: str
        :type wordDict: List[str]
        :rtype: bool
        """
        # 初始化标记列表
        flag = [True]+[False]*len(s)

        for start in range(len(s)):
            if flag[start]:
                for end in range(start+1, len(s)+1):
                    if s[start:end] in wordDict:
                        flag[end] = True
        return flag[-1]


if __name__ == "__main__":
    s = "aaaaaaa"
    wordDict = ["aaaa","aaa"]
    flag = Solution().wordBreak(s, wordDict)
    print(flag)
```

执行效率中等吧，在 70% 左右。

![image.png](https://pic.leetcode-cn.com/0befe32aab27834ea8e795c9b74cae547d3f9933f721f4cb6bf9d9ed8ffa77ca-image.png){:width=500}
{:align=center}
