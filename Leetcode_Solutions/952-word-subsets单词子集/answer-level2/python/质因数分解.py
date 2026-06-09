首先需要知道，对于每一个数，它的质因数分解是唯一的，因此不同的质因数相乘必定得到的是不同的数。因此，我们可以将26个字母转化成不同的质数，这样就将字符串转化成唯一的大整数。
问题中A的通用字符串定义转化一下就是，该字符串所对应的大整数应该是B中所有大整数的倍数，那么我们仅需要找到B中所有大整数的最小公倍数，
```
class Solution:
    def wordSubsets(self, A: List[str], B: List[str]) -> List[str]:
        Alth = len(A)
        Blth = len(B)
        if not Alth or not Blth:
            return []
        cton = {"a": 2, "b": 3, "c": 5, "d": 7, "e": 11, "f": 13, "g": 17,
                "h": 19, "i": 23, "j": 29, "k": 31, "l": 37, "m": 41, "n": 43,
                "o": 47, "p": 53, "q": 59, "r": 61, "s": 67, "t": 71,
                "u": 73, "v": 79, "w": 83, "x": 89, "y": 97, "z": 101}
        Anum = []
        Ball = 1
        res = []
        for s in A:
            temp = 1
            for c in s:
                temp *= cton[c]
            Anum.append(temp)


        for s in B:
            temp = Ball
            for c in s:
                if temp%cton[c]:
                    Ball*=cton[c]
                else:
                    temp//=cton[c]

        for Apos in range(Alth):
            if not Anum[Apos] % Ball:
                res.append(A[Apos])
        return res
```


