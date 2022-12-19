很多人都写明白了，把S1和S2的头或者尾比，出现字符相同依次递归。
先写个质数表，慢慢乘不就行了。为什非要加来加去的？
没仔细算mux用int会不会溢出（int64可能更可靠），不过可以跑过。


```
var tmp=map[rune]int{
    'a':2,
    'b':3,
    'c':5,
    'd':7,
    'e':11,
    'f':13,
    'g':17,
    'h':19,
    'i':23,
    'j':29,
    'k':31,
    'l':37,
    'm':41,
    'n':43,
    'o':47,
    'p':53,
    'q':59,
    'r':61,
    's':67,
    't':71,
    'u':73,
    'v':79,
    'w':83,
    'x':89,
    'y':97,
    'z':101}
func isScramble(s1 string, s2 string) bool {
    if s1==s2{
        return true
    }
    length:=len(s1)
    for i:=1;i<length;i++{
        if mux(s1[:i])==mux(s2[:i]){
            if isScramble(s1[:i],s2[:i])&&isScramble(s1[i:],s2[i:]){
                return true
            }

        }
        if mux(s1[:i])==mux(s2[length-i:]){
            if isScramble(s1[:i],s2[length-i:])&&isScramble(s1[i:],s2[0:length-i]){
                return true
            }
        }
    }
    return false
}
func mux(s1 string)int{
    ans:=1
    for  _,j:=range(s1){
        ans=ans*tmp[j]
    }
    return ans
}
```
