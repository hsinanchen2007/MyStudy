```
class Solution:
    def uniqueMorseRepresentations(self, words: List[str]) -> int:
        import string
        str1 = string.ascii_lowercase
        pwd = [".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."]
        dic = {}
        re = []
        for i in range(len(str1)):
            dic[str1[i]]=pwd[i]
        for word in words:
            res = ''
            for j in word:
                res += dic[j]
            re.append(res)
        return len(set(re))
```
