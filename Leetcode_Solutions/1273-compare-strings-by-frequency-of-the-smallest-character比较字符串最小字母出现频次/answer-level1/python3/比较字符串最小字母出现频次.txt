```
class Solution:
    def numSmallerByFrequency(self, queries: List[str], words: List[str]) -> List[int]:
        if not queries and not words:
            return 
        
        quelen = len(queries)
        wordlen = len(words)
        queResult = []
        wordResult = []
        answer = [0] * quelen
        for j in range(wordlen):
            wordsort = sorted(words[j])
            if len(wordsort) == 0:
                wordResult.append(0)
            else:
                wordResult.append(wordsort.count(wordsort[0]))  # 统计第一个字母出现的字数

        for i in range(quelen):
            quesort = sorted(queries[i])
            if len(quesort) == 0:
                quenum = 0
                # queResult.append(0)
            else:
                quenum = quesort.count(quesort[0])
                # queResult.append(quesort.count(quesort[0]))  # 统计第一个字母出现的字数
            answer[i] = sum([1 if c > quenum else 0 for c in wordResult])
        return answer
```
改用二分查找模块bisect，效率显著提升
            answer[i] = wordlen - bisect.bisect(wordResult, quenum)
