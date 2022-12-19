```
class Solution(object):
    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        map={'2': 'abc', '3':'def', 
            '4':'ghi','5':'jkl','6':'mno',
            '7':'pqrs','8':'tuv','9':'wxyz'}
        l = len(digits)
        if l==0: return []
        res = []
        def F(digits):
            l = len(digits)
            if l==0: return []
            res = []
            head = digits[0]
            cs = map[head]
            sfxs = F(digits[1:])
            for i in range(len(cs)):
                c = cs[i]
                tres = []
                if len(sfxs) == 0:
                    tres.append(c)
                for j in range(len(sfxs)):
                    tres.append(c+sfxs[j])
                res += tres
            return res
        return F(digits)
```
