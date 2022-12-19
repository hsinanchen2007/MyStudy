```
class Solution:
    def reverseVowels(self, s):        
        word = 'aeiouAEIOU'
        filter_word = [i for i in s if i in word]

        ret = list(s)
        for idx, val in enumerate(ret):
            if val in word:
                ret[idx] = filter_word.pop()

        return ''.join(ret)
```
