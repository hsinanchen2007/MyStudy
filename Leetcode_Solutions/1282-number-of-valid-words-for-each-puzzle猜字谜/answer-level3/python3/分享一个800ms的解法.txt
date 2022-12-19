```
class Solution:
    def state_of_word(self, word):
        """
        字符串的状态是包含的不同的字符
        :param word: 
        :return: 
        """
        s = 0
        for c in word:
            s |= 1 << (ord(c) - ord('a'))
        
        return s
    
    def sub_states(self, s):
        """
        一个谜面的状态是s，返回所有可能的谜底的状态
        :param s: 
        :return: 
        """
        q = [0]
        for i in range(26):
            if s & (1 << i) > 0:
                q.extend([v | (1 << i) for v in q])
        return q

    def findNumOfValidWords(self, words: List[str], puzzles: List[str]) -> List[int]:
        N = len(puzzles)
        count = collections.defaultdict(int)
        for i, w in enumerate(words):
            count[self.state_of_word(w)] += 1
    
        ans = [0] * N
        for i, p in enumerate(puzzles):
            s0 = self.state_of_word(p[0])
            st = self.sub_states(self.state_of_word(p))
            
            # 排除掉不包含谜面第一个字符的谜底
            ans[i] = sum([count[t] for t in st if t & s0 > 0])
    
        return ans
```
