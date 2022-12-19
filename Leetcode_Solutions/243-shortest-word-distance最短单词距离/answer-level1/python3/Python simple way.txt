```
 class Solution(object):
	def shortestDistance(self, words, word1, word2):       
        res=len(words)
        pos1,pos2=-res,-res
        for i, num in enumerate(words):
            if num==word1:
                pos1=i
            elif num==word2:
                pos2=i
            else:
                continue
            res = min(res, abs(pos1-pos2))
        return res
```
