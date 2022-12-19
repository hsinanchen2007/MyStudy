### 代码
```python3
class Solution:
    def isMatch(self, string: str, pattern: str) -> bool:
        # 如果 string 或者 pattern 有一个为空的话，那么输入就是错误的
        # 也就意味着匹配失败
        if string is None or pattern is None:
            return False

        # 如果 string 和 pattern 长度都为 0 的话，代表匹配结束
        # 如果匹配能够成功完成，那么就意味着匹配成功
        if len(string) == 0 and len(pattern) == 0:
            return True

        # 如果 string 还有字符，而  pattern 已经没有字符了，那么就意味着不能再匹配了
        # 也就是匹配失败
        if len(string) != 0 and len(pattern) == 0:
            return False

        # 定义匹配符号
        wildcard, dot = '*', '.'

        # '*' 需要一次性处理两个字符，我们把它看作一体
        if len(pattern) >= 2 and pattern[1] == wildcard:
            # 匹配 '*' 对应的字符 不存在的情况，即 直接跳过匹配
            # e.g. string: '', pattern: 'c*'
            # e.g. string: 'a', pattern: 'c*a'
            if self.isMatch(string, pattern[2:]):
                return True

            # 匹配 '.*'
            # e.g. string: 'c', pattern: '.*'
            if string and pattern[0] == dot:
                # 匹配成功之后匹配下一个字符
                return self.isMatch(string[1:], pattern)

            # 匹配 'a*'
            # e.g. string: 'a', pattern: 'a*'
            if string and string[0] == pattern[0]:
                # 匹配成功之后匹配下一个字符
                return self.isMatch(string[1:], pattern)
        else:
            # 匹配单个字符
            # e.g. string: 'a', pattern: 'a'
            if string and string[0] == pattern[0]:
                return self.isMatch(string[1:], pattern[1:])
            # 匹配 '.'
            # e.g. string: 'a', pattern: '.'
            if string and pattern[0] == dot:
                return self.isMatch(string[1:], pattern[1:])

        # 以上出现的匹配都失败了，那么就是匹配失败
        return False
```