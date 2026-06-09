### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def maxScoreWords(self, words: List[str], letters: List[str], score: List[int]) -> int:
        from collections import Counter
        c = Counter(letters)
        n = len(words)
        self.ans = 0
        def compart(count1,count2):
            for key in count1:
                if key not in count2:
                    return False
                elif count1[key]>count2[key]:
                    return False
            return True
                    
        def backtrack(i,counterererer,point):
            if i ==n:
                self.ans = max(self.ans,point)
                return
            backtrack(i+1,counterererer,point)
            for j in range(i,n):
                temp = Counter(words[j])
                if compart(temp, counterererer):
                    p = 0
                    for c in words[j]:
                        p+=score[ord(c)-ord('a')]
                    backtrack(j+1,counterererer-temp,point+p)
        
        backtrack(0,c,0)
        return self.ans
```