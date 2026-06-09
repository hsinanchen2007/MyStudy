
```java
// 假设 S 由 s 重复 N (N>1)此组成，则 S+S由s重复2N次组成，
// 去掉头和尾相当于破坏了2个s, 此时 S+S[1:-1] 仍包含(2N-2)个s
// 若 2N-2 == 0，说明N=1，S由1个s组成，返回false
// 若 2N-2>0，说明 N>=2，S由两个以上s组成，返回true
return (s+s).substring(1,(s+s).length()-1).contains(s);
```