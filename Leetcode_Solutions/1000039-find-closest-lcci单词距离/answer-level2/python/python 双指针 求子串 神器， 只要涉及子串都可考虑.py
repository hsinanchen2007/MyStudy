```
class Solution(object):
    def findClosest(self, words, word1, word2):
        wordDict = {word1:0, word2:0}
        forms = 0

        left = 0
        right = 0
        n = len(words)
        ans = n
        while right < n:
            if forms == 2:
                key = words[left]
                if key in wordDict:
                    wordDict[key] -= 1

                    if wordDict[key] == 0:
                        forms -= 1
                        ans = min(ans, right - left - 1)
                
                left += 1

            else:
                key = words[right]
                if key in wordDict:
                    wordDict[key] += 1

                    if wordDict[key] == 1:
                        forms += 1
                
                right += 1

        return ans

```
