### 解题思路
KMP的next 数组求解的就是 快乐前缀 （满足前缀=后缀的最长前缀串）

### 代码

```cpp
    int next(string& p) {
        int N = p.size();
        vector<int> n(N, 0);
        int j = 1, k = 0;
        while (j < N) {
            if (-1 == k || p[k] == p[j]) n[j++] = ++k;
            else k = (k > 0) ? n[k-1] : -1;
        }
        return n[N-1];
    }
    
    string longestPrefix(string s) {
        return s.substr(0, next(s));
    }
```


> 附录：KMP详解

# KMP 字符串匹配算法

***

**KMP的核心思想在于 从模式串本身寻找特征，当一个字符不匹配时，直接移动到下一个位置，无需做多余的比较，时间复杂度O(N+M)**

***
## 1. 特征数的求法
特征数：满足前缀和后缀相同的最大子串长度

公式定义：
**Let's define:**

$$
next[j] =
\begin{cases}
\max\ of\ \{k\ |\ 0<k<j\ \&\&\ P_0P_1...P_{k-1}=P_{j-k+1}P_{j-k+2}...P_j \} \\
0,\ if\ k\ not\ exist
\end{cases}
$$

从匹配成功的j-1如何推到j ？

推导过程：
$let\ \text{next[j-1] = k}$
$i.e\ P_0P_1...P_{k-1}=P_{j-k+1}P_{j-k+2}...P_{j-1}$
*To extend case to j*
$$
\begin{cases}
next[j] =k+1,\ if\ P_k = P_j\quad (1) \\
k = next[k-1],\ otherwise\quad (2)
\end{cases}
$$
***Why?***
(1) 显而易见，重点讨论 (2) 当 $P_k 和 P_j$ 不匹配时，要重新找一个 $k^*$ 能满足最长前缀的需求，这个前缀串满足：
$P_0P_1...P_{k^*}=P_{j-k^*}P_{j-k^*+2}...P_{j}$
那么一定有
$P_0P_1...P_{k^*-1}=P_{j-k^*}P_{j-k^*+2}...P_{j-1}$
而我们已知 
$P_0P_1...P_{k-1}=P_{j-k+1}P_{j-k+2}...P_{j-1}$
也就是 $k^*$ 一定有
$P_0P_1...P_{k^*-1}=P_{k-k^*}P_{k-k^*+1}...P_{k-1}$
要找这样的 $k^*$， $next[k-1]$ 一定是其中最大的那个（快乐前缀的定义），所以才有 (2) 成立

代码：
```c++
//直接版
vector<int> get_next(string& P) {
    int N = P.size();
    vector<int> next[N];
    next[0] = 0;    //一个字符，最长前缀为0
    int k = 0, j = 1; //k 标识长度，j标识下标
    while (j < N) {
        if (-1 == k) {
            next[j] = 0;
            k++;
            j++;
        } else if (P[k] == P[j]) {
            next[j] = k+1;
            k++;
            j++;
        } else {
            k = k > 0 ? next[k-1] : -1;
        }
    }
    return next;
}


//精简版
vector<int> get_next(string& P) {
    vector<int> next(P.size(), 0);
    int k = 0, j = 1; //k 标识长度，j标识下标
    while (j < P.size()) {
        if (-1 == k || P[k] == P[j]) next[j++] = ++k;
        else k = k ? next[k-1] : -1;
    }
    return next;
}
```

## 2. KMP 算法
理解了next 特征数的产生，再来看KMP算法就比较直接了，当模式串与目标串不匹配时，移动模式串的下标到next。

```c++
//brute force， O(N*M)
int find(string& T, string& P) {
    if (P.size() > T.size()) return -1;
    for (int i = 0; i < T.size(); ++i) {
        bool found = true;
        for (int j = 0; j < P.size(); ++j) {
            if (P[i] != P[j]) {
                found = false;
                break;
            }
        }
        if (found) return i;
    }
    return -1;
}

//KMP, O(M+N)
int kmp(string& T, string& P) {
    if (P.size() > T.size()) return -1;
    vector<int> next = get_next(P);
    int i = 0, j = 0, M = T.size(), N = P.size();
    while (i < M && j < N) {
        if (T[i] == P[j]) {
            ++i;
            ++j;
        } else if (0 == j) { //开头就不匹配，移动i直到匹配
            ++i;
        } else {
            j = next[j-1]; //只是第j个字符不匹配，前j-1个匹配，那么j-1的最长前缀不用再检查了，直接到j-1快乐前缀的下一个字符
        }
    }
    return j == N ? i - j : -1;
}
```