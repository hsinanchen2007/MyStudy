
```python3
class Solution:
    def minimumLengthEncoding(self, words) -> int:
        size = len(words)
        if not size:
            return 0
        # 按长度排序
        words.sort(key=lambda x:-len(x))
        # 初始化结果字符串
        S = words[0] + '#'
        for elem in words:
            # 如果不存在，直接加在末尾
            if S.find(elem) == -1:
                S += elem + '#'
            # 存在，并且下一位是#， 表明新elem和S中某个结尾重复，则直接忽略
            elif S[S.find(elem) + len(elem)] == '#':
                continue
            # 虽然重复，但不是在结尾重复
            else:
                S += elem + '#'
        return len(S)
```