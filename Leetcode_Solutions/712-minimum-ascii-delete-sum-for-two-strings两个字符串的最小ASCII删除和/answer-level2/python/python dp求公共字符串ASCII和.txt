```
# up to c2 in s2, asciisum[i] = max asciisum from s1[0] up to s1[i]
# for next a in s2, for next i
# if s1[i]==a: newascs[i]=ascs[i-1]+ord(a)
# if not: newascs[i]=max(newascs[i-1], ascs[i])
# ascs = newascs
# 
# aaabbbcccdddeee: s1
# abcdeabcdeabcde: s2 (为方便假设所有ascii值为1)
# 111222333444555 up to abcde in s2, for next a,
# 122222333444555 up to abcdea
# 122333333444555 up to abcdeab
# 123333444555666 up to abcde abcde a
# 123444444555666 up to abcde abcde ab
```

```
class Solution:
    def minimumDeleteSum(self, s1: str, s2: str) -> int
        ascs = [0] * (len(s1) + 1)  # asciisum
        for c2 in s2:
            newascs = [0] * len(ascs)
            for i in range(1, len(ascs)):
                if s1[i-1] == c2:
                    newascs[i] = ascs[i-1] + ord(c2)
                else:
                    newascs[i] = max(newascs[i-1], ascs[i])
            ascs = newascs
        toint = lambda string: sum([ord(c) for c in string])
        return toint(s1) + toint(s2) - 2 * ascs[-1]
```
