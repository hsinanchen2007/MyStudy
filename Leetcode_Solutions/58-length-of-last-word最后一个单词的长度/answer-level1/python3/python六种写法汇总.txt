```py
# 方法 1
class Solution1:
    def lengthOfLastWord(self, s):
        # 去掉尾部空格
        s = s.rstrip()
        # 空字符
        if not s:
            return 0
        # 尾部单词（最后无空格）
        l = len(s)
        # 尾部单词前有空格
        for i in range(l - 1, -1, -1):
            if s[i] == " ":
                return l - i - 1
        # 仅一个单词
        return l


# 方法 2：rfind()函数获取尾部单词前的空格索引值
class Solution2:
    def lengthOfLastWord(self, s):
        s = s.rstrip()
        if not s:
            return 0
        res = s.rfind(" ")
        if res != -1:
            return len(s) - res -1
        return len(s)


# 方法 3：split()函数获取最后一个单词
class Solution3:
    def lengthOfLastWord(self, s):
        s = s.split()
        if not s:
            return 0
        return len(s[-1])


# 方法 4：方法 3 改进写法
class Solution4:
    def lengthOfLastWord(self, s):
        return len(s.rstrip().split(" ")[-1])


# 方法 5：去掉尾部空格再反转字符串后，split()函数获取第一个单词，只需分割一次
class Solution5:
    def lengthOfLastWord(self, s):
        return len(s.rstrip()[::-1].split(" ", 1)[0])


# 方法 6：反转去掉头部空格，再获取第一个单词长度
class Solution6:
    def lengthOfLastWord(self, s):
        s = s[::-1].lstrip()
        for i in range(len(s)):
            if s[i] == " ":
                return i
        return len(s)
```
