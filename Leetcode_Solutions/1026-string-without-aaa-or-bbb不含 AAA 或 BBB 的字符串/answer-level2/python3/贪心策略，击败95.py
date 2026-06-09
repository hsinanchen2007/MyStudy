假设A>B。
ans = ''
每次迭代ans追加'aab'，A自减2,B自减1；
直到出现A == B或者A+1 == B的情况出现以后(不可能出现B-A > 1)，每次迭代追加'ab'，直到结束。

```
class Solution:
    def strWithout3a3b(self, A: int, B: int) -> str:
        ans = ''
        if A == B:
            return 'ab'*A
        elif A > B:
            while (A>B):
                ans += 'aab'
                A -= 2
                B -= 1
                if B==0:
                    return ans+'a'*A
            if A == B:
                while A:
                    ans += 'ab'
                    A -= 1
            else:
                while A:
                    ans += 'ab'
                    A -= 1
                ans +='b'
        else:
            while (B>A):
                ans += 'bba'
                A-=1
                B-=2
                if A==0:
                    return ans+'b'*B
            if A==B:
                while B:
                    ans += 'ba'
                    B-=1
            else:
                while B:
                    ans += 'ba'
                    B-=1
                ans += 'a'
        return ans
```
