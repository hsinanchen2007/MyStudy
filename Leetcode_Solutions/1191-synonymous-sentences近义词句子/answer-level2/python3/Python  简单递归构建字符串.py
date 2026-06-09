![image.png](https://pic.leetcode-cn.com/02df71b7f0b5a38da0258e3bf5f98fa6001f4449bd4dbe3668bb3e721e6afc14-image.png)


```
'''
邻接表记录邻接关系，递归构建字符串
'''


from typing import List
class Solution:
    # 获取所有相邻的单词
    def get_path(self, word, m, ans, visited):
        if word in visited:
            return

        ans.append(word)
        visited.add(word)
        if word in m:
            for next in m[word]:
                self.get_path(next, m, ans, visited)

    def solve(self, cur, words, m):
        l = []
        self.get_path(words[cur], m, l, set())

        if cur == len(words)-1:
            return l

        ans = []
        suffix_list = self.solve(cur+1, words, m)
        for suffix in suffix_list:
            for w in l:
                ans.append(w + ' ' + suffix)
        return ans

    def generateSentences(self, synonyms: List[List[str]], text: str) -> List[str]:
        # 邻接表
        m = {}
        for w1, w2 in synonyms:
            for w in [w1, w2]:
                if w not in m:
                    m[w] = []
            m[w1].append(w2)
            m[w2].append(w1)

        ans = self.solve(0, text.split(' '), m)
        return sorted(ans)
```
