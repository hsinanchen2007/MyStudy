```
class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """

        if len(s) == 0:
            return True

        str_dict = {"{":"}", "(":")","[":"]", "}":"{", ")":"(","]":"["}
        foo = [s[0]]
        for i in range(1,len(s)):
            foo.append(s[i])

            if len(foo) >=2 and foo[-1] == str_dict[foo[-2]]:
                foo = foo[:-2]
            else:
                pass
        return False or len(foo)==0
        
```

        