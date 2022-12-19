```
class Solution:
    def shortestDistance(self, words: List[str], word1: str, word2: str) -> int:
        # 1. brute force O(n^2)
        # min_distance = size = len(words)
        # for i in range(size):
        #     if words[i] == word1:
        #         for j in range(size):
        #             if words[j] == word2:
        #                 min_distance = min(min_distance, abs(i-j))
        # return min_distance
        
        # 2. O(n)
        n = m = min_distance = size = len(words)
        for i in range(size):
            if words[i] == word1:
                n = i
            elif words[i] == word2:
                m = i
            
            if m != size and m != size:
                min_distance = min(min_distance, abs(m-n))
            
        return min_distance
                
                
            
        
```
