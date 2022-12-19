### 解题思路
先处理了一下words中的每一个单词的信息和letters里的信息，然后暴力的搜索+剪枝。
代码写的极丑。

### 代码

```python3
class Solution:
    def maxScoreWords(self, words: List[str], letters: List[str], score: List[int]) -> int:
        if not letters:
            return 0
        
        letter_cnt = {}
        score_letter = 0
        for letter in letters:
            letter_cnt[letter] = letter_cnt.get(letter, 0) + 1
            score_letter += score[ord(letter) - ord('a')]
            
        score_word = []
        for word in words:
            s = 0
            word_cnt = {}
            for c in word:
                s += score[ord(c) - ord('a')]
                word_cnt[c] = word_cnt.get(c, 0) + 1
            score_word.append((s, word, word_cnt))
            
        score_word.sort(reverse=True)
        self.res = 0
        self.dfs(score_word, letter_cnt, score_letter, 0)
        return self.res
        
    def dfs(self, score_word, letter_cnt, score_letter, cur):
        if not score_word:
            self.res = max(self.res, cur)
            return
            
        if score_letter <= self.res - cur:
            return
        
        for i in range(len(score_word)):
            word_info = score_word[i]
            flag = True
            for k, v in word_info[2].items():
                if letter_cnt.get(k, 0) < v:
                    flag = False
                    break
            if not flag:
                continue
            for k, v in word_info[2].items():
                letter_cnt[k] -= v
            score_letter -= word_info[0]
            cur += word_info[0]
            self.dfs(score_word[i+1:], letter_cnt, score_letter, cur)
            cur -= word_info[0]
            score_letter += word_info[0]
            for k, v in word_info[2].items():
                letter_cnt[k] += v
        self.res = max(self.res, cur)
```