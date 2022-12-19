![image.png](https://pic.leetcode-cn.com/2562fd26bdb001bc7d47871e12bc5e0a17cb6199c77e06ac75e826e605d873e8-image.png)


```
from typing import List
from collections import Counter

'''
思路：
转换成01背包问题求解，包的容量就是剩余可供使用的字符和其个数
往包里面放单词，每个单词开销就是单词包含的字符，每个单词的
价值就是单词包含字符的分数和
'''

class Solution:

    def getKey(self, n, c: Counter):
        s = str(n)
        for ch, cnt in c.items():
            s += f',{ch},{str(cnt)}'
        return s

    #用 Counter中对应的字符剩余量，拼写前n个单词，返回能得到的最大收益
    def solve(self, n, words, word_scores, leftChar: Counter, memo) -> int:
        if n == -1:
            return 0

        key = self.getKey(n, leftChar)
        if key in memo:
            return memo[key]

        c = Counter(words[n])
        flag = True
        for ch, need_num in c.items():
            if ch not in leftChar or leftChar[ch] < need_num:
                flag = False
                break

        ans = -1
        if flag:
            for ch, need_num in c.items():
                leftChar[ch] -= need_num

            ans = word_scores[n] + self.solve(n-1, words, word_scores, leftChar, memo)

            for ch, need_num in c.items():
                leftChar[ch] += need_num

        ans = max(ans, self.solve(n-1, words, word_scores, leftChar, memo))
        memo[key] = ans
        return ans

    def maxScoreWords(self, words: List[str], letters: List[str], score: List[int]) -> int:
        if len(words) == 0 or len(letters) == 0:
            return 0

        word_scores = [0 for _ in range(len(words))]
        for i, w in enumerate(words):
            c = Counter(w)
            sum = 0
            for ch, cnt in c.items():
                sum += score[ord(ch) - ord('a')] * cnt
            word_scores[i] = sum

        return self.solve(len(words)-1, words, word_scores, Counter(letters), {})

print(Solution().maxScoreWords(

words = ["dog","cat","dad","good"], letters = ["a","a","c","d","d","d","g","o","o"], score = [1,0,9,5,0,0,3,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0]

))
```
