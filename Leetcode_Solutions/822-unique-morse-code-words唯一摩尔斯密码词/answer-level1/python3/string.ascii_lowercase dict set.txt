```
class Solution:
    def uniqueMorseRepresentations(self, words: List[str]) -> int:
        import string
        d = dict(zip(string.ascii_lowercase,[".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."]))
        codes = []
        for word in words:
            code = ''
            for w in word:
                 code += d[w]
            codes.append(code)
        return len(set(codes))
```
