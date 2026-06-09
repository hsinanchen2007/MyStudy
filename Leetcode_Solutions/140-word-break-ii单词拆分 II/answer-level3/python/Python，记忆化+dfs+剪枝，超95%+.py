![lc140.png](https://pic.leetcode-cn.com/ccdf2b410caa59fc2433a568fbfb168187532909ef8e89b2f0013f051313de80-lc140.png)

剪枝同样能大大减小空间复杂度，对aaaaaaaaaabaaaa那个用例不用特意优化
```python
    def wordBreak(self, s: str, wordDict: list) -> list:
        if not s:
            return []
        _len, wordDict = len(s), set(wordDict)  # 转换成字典用于O(1)判断in
        _min, _max = 2147483647, -2147483648   # 记录字典中的单词的最长和最短长度，用于剪枝
        for word in wordDict:
            _min = min(_min, len(word))
            _max = max(_max, len(word))

        def dfs(start):  # 返回s[start:]能由字典构成的所有句子
            if start not in memo:
                res = []
                for i in range(_min, min(_max, _len-start)+1):  # 剪枝，只考虑从最小长度到最大长度查找字典
                    if s[start: start+i] in wordDict:  # 找到了
                        res.extend(list(map(lambda x: s[start: start+i]+' '+x, dfs(start+i))))  # 添加
                memo[start] = res  # 加入记忆
            return memo[start]

        memo = {_len: ['']}  # 初始化记忆化存储
        return list(map(lambda x: x[:-1], dfs(0)))  # 去掉末尾多出的一个空格
```
