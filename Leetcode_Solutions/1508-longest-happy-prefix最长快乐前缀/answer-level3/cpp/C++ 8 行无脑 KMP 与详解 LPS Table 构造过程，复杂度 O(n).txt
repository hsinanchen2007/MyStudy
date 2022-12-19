### 复杂度

时间复杂度 $O(n)$，空间复杂度 $O(n)$。

### 简单说明

似乎 KMP 算法的代码并不比暴力算法的长嘛 (大雾)
其实没有在规定时间内解完此题，早知道 Python 能暴力求解 T.T

关于 KMP 算法的实现，我参考的是 [BTech Smart Class](http://www.btechsmartclass.com/data_structures/knuth-morris-pratt-algorithm.html) 的图文解释。LeetCode 上的经典 KMP 算法题可以是 [28. 实现 strStr()](https://leetcode-cn.com/problems/implement-strstr/)。其说明会放在代码部分之后。

事实上，解这道题并没有用到所有 KMP 算法的过程，只利用了其中的 LPS Table (Longest proper Prefix which is also Suffix，最长相同的前缀与后缀长度表，实际上这个 Table 是向量)。

### 代码

耗时大约 30-60 ms。关于代码中出现的三种 situation 的讨论，放在代码之后的文段中。

```c++
class Solution {
public:
    string longestPrefix(string s) {
        vector<int> lps(s.size(), 0);
        size_t i = 0, j = 1;
        while (j < s.size()) {
            if (s[i] == s[j]) lps[j++] = (i++) + 1;  // situ.1
            else if (i != 0) i = lps[i - 1];         // situ.2
            else lps[j++] = 0;                       // situ.3
        }
        return s.substr(0, lps.back());
    }
};
```

### KMP 算法中 LPS Table 的构造

**例子**

- 例 1：`abcdabd`
  ```
  s    a b c d a b d
  lps  0 0 0 0 1 2 0
  ```
  譬如 `lps[5] = 2`，代表以 `s[5] = 'b'` 为末尾的情况下，长度为 `2` 的前缀 `s[0:2]` 与后缀 `s[4:6]` 都是 `ab`。
- 例 2：`aabaaac`
  ```
  s    a a b a a a c
  lps  0 1 0 1 2 2 0
  ```
  譬如 `lps[5] = 2`，代表以 `s[5] = 'a'` 为末尾的情况下，长度为 `2` 的前缀 `s[0:2]` 与后缀 `s[4:6]` 都是 `aa`。
  而 `lps[4] = 2`，亦代表以 `s[4] = 'a'` 为末尾的情况下，长度为 `2` 的前缀 `s[0:2]` 与后缀 `s[3:5]` 都是 `aa`。

**具体构造过程**

在程序中，要实现 LPS Table，需要构建左指针 `i` (前缀指针) 与右指针 `j` (后缀指针)；并对下述三种情况作分类讨论：
1. 若 `s[i] = s[j]`，即前缀指针与后缀指针所指字符相等，则两者都加一；譬如
   ```
   s        a a b a a a c    action
   lps      0 1 0
   pointer  i     j          situ.1 => lps[j] = lps[i] + 1, ++i, ++j
   lps      0 1 0 1
   pointer    i     j        situ.1 => lps[j] = lps[i] + 1, ++i, ++j
   lps      0 1 0 1 2
   pointer      i     j
   ```
2. 若 `s[i] != s[j]` 但指针 `i != 0` 即不处在头字符上，那么更新前缀指针 `i = lps[i - 1]`；譬如
   ```
   s        a a b a a a c    action
   lps      0 1 0 1 2
   pointer      i     j      situ.2 => i = lps[i - 1] = 1
   lps      0 1 0 1 2
   pointer    i       j      situ.1 => lps[j] = lps[i] + 1, ++i, ++j
   lps      0 1 0 1 2 2
   pointer      i       j    situ.2 => i = lps[i - 1] = 0
   lps      0 1 0 1 2 2
   pointer  i           j
   ```
3. 若 `s[i] != s[j]` 且指针 `i == 0` 即处在头字符上，那么令更新 `lps[j] = 0` 并且前移后缀指针 `j`；譬如
   ```
   s        a a b a a a c    action
   lps      0 1 0 1 2 2
   pointer  i           j    situ.3 => lps[j] = 0; ++j
   lps      0 1 0 1 2 2 0
   pointer  i             j  pointer j approach end, exit loop
   ```

**返回结果**

这个程序的返回结果即 LPS Table `lps` 的最后一个值。


### 附：完成 LeetCode 28 题的代码

```c++
// KMP Algorithm: http://www.btechsmartclass.com/data_structures/knuth-morris-pratt-algorithm.html

class Solution {
public:
    int strStr(string haystack, string needle) {
        // 0. Exclude empty needle situation and smaller haystack situation
        if (needle.empty()) return 0;
        if (haystack.size() < needle.size()) return -1;
        // 1. Create LPS table
        //    Make sure that from lps[1], value of lps[i] refers to same string length from front of needle
        // A B C D A B D ==> j
        // 0 0 0 0 1 2 0 ==> i
        // A A B A A A C   Fifth A: (i, j) : (1, 4) -> situ.1 (2, 5) -> situ.2 (1, 5) -> situ.1 (2, 6)
        // 0 1 0 1 2 2 0               lps :           lps[4] = 2                        lps[5] = 2
        vector<int> lps(needle.size(), 0);
        size_t i = 0, j = 1;
        while (j < needle.size()) {
            if (needle[i] == needle[j]) lps[j++] = (i++) + 1;  // situ.1
            else if (i != 0) i = lps[i - 1];                   // situ.2
            else lps[j++] = 0;                                 // situ.3
        }
        // 2. Loop the LPS table
        //    situation 1: A B C D A B   A B C D  ph = 0  -->  n - lps[n - 1] = 6 - lps[5] = 6 - 2 = 4
        //                 A B C D A B D          n = 6   -->  lps[n] = idx[5] = 2
        //             ==>         A B C D A B D  next compare ph + n = 6
        //    situation 2: E E E E E E E          ph = 0  -->  ph + 1 = 1
        //                 A B C D A B D          n = 0   -->  lps[n] = 0
        //             ==>   A B C D A B D        next compare ph + n = 1
        auto ph = haystack.cbegin(); int n = 0;
        while (ph + n - haystack.cend() < 0) {
            if (*(ph + n) != needle[n]) {
                ph += n == 0 ? 1 : n - lps[n - 1];
                n = n == 0 ? 0 : lps[n - 1];
            }
            else if (n == needle.size() - 1) return int(ph - haystack.cbegin());
            else ++n;
        }
        return -1;
    }
};
```