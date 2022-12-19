通过数学，容易看出IV实际上可以看做V+I-2*I，IX等可以以此类推。因此写出代码：```
代码块
```class Solution:
    def romanToInt(self, s: str) -> int:
        a=s.count("I")
        b=s.count("V")
        c=s.count("X")
        d=s.count("L")
        e=s.count("C")
        f=s.count("D")
        g=s.count("M")
        A=s.count("IV")
        B=s.count("IX")
        E=s.count("XL")
        F=s.count("XC")
        G=s.count("CD")
        H=s.count("CM")
        return a+5*b+10*c+50*d+100*e+500*f+1000*g-2*(A+B)-20*(E+F)-200*(G+H)

