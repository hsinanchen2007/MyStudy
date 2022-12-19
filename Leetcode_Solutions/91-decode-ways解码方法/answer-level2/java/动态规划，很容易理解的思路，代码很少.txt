刚开始用递归的时候超时了，就改成了动态规划。
感觉和爬楼梯的题目是一个道理，只是多了判断条件。
加了公式便于理解。

公式：
$$
S(n) = a + b \\\\
$$
$$
a=\begin{cases}
0,\quad if \ a_n = 0 \\\\
S(n-1),\quad else
\end{cases}
$$
$$
b=\begin{cases}
0,\quad if \ a_{n-1}a_n > 26 \\\\
S(n-1),\quad else
\end{cases}
$$
$$
S(0) = S(1) = 1
$$

代码：
```java []
public int numDecodings(String s) {
        if (s.charAt(0) == '0') return 0;
        
        if (s.length() == 1) return 1;
        
        int n0 = 1;
        int n1 = 1;
        
        for (int i = 1; i < s.length(); i++) {
            int a = s.charAt(i) == '0' ? 0 : n1;
            int b = s.charAt(i-1) == '1' || (s.charAt(i-1) == '2' && s.charAt(i) <= '6') ? n0 : 0;
            n0 = n1;
            n1 = a + b;
        }
        return n1;
    }
```

