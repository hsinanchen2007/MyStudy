## 总述

要有符合提议的字符串构造模式，则一定只有如下可能性：

- B 就是 A 的子串
- B 可分为 3 部分：
    - 开头有 A 的后缀
    - 中间是 A 的重复（重复数为非负整数）
    - 结尾有 A 的前缀

这样，可以相应使用穷举法暴力列举所有答案，进行字符串匹配；或者按部就班去拆解 B 字符串，进行分部匹配和计算。

## 解法一：穷举法

### 简述

可以设 `t = B.length() / A.length()`，那么 A 最少重复 t 次，最多重复 t + 2 次。

注意：本题测试数据比较宽松，本解法即使不用 KMP 算法而用库函数的 `contains()` 一样能 AC，只是耗时较多。

### 代码

原始版本：

```java
class Solution {
   public int repeatedStringMatch(String A, String B) {
        int t = B.length() / A.length();
        for (int i = 0; i < 3; i++) {
            if (A.repeat(i + t).contains(B)) return i + t;
        }
        return -1;
    }
}
```

KMP 版本：

```java
class Solution {
   public int repeatedStringMatch(String A, String B) {
        int t = B.length() / A.length();
        for (int i = 0; i < 3; i++) {
            if (kmp(A.repeat(i + t), B) >= 0) return i + t;
        }
        return -1;
    }

    private int kmp(String text, String pattern) {
        int i = 0;
        int j = 0;
        int[] next = nextArray(pattern);

        for (; i < text.length() && j < pattern.length(); i++, j++) {
            while (j != -1 && text.charAt(i) != pattern.charAt(j)) j = next[j];
        }
        return j == pattern.length() ? i - j : -1;
    }

    private int[] nextArray(String str) {
        if (str.isEmpty()) return new int[0];
        int[] next = new int[str.length()];
        next[0] = -1;
        for (int i = 1; i < str.length(); i++) {
            int t = next[i - 1];
            while (t != -1 && str.charAt(i - 1) != str.charAt(t)) t = next[t];
            next[i] = t + 1;
        }
        return next;
    }
}
```

## 解法二：字符串滚动法

### 简述

本解法关键有两步：

1. B 的开头可能有 A 的后缀，找到这个后缀在 A 中的位置
2. 把 A 当做“滚筒”去印刷 B 的剩余字符，即：
    - A 从第 1 步得到的位置开始遍历，B 从头开始，进行字符一一匹配
    - 一旦用完 A 的字符，再从 A 的开头重新开始匹配（像是）

其中，第 2 步的“滚动印刷”操作非常简单，利用余数的性质即可完成，注意每次下标为 0 就代表多使用一个 A。滚动印刷过程中，如果发生了字符串不匹配，那么 A 无法通过重复来包含子串 B。

本解法关键是第 1 步的实现：
    1. 倍增字符串 A 构造字符串 a
    2. 从 B 的开头截取长度为 `min(A.length(), B.length())` 的前缀构造 b
    3. 使用 `a.indexOf(b)` 可以得到相应的结果

注意：那此处 b 应该是 a 的子串，否则无论 A 如何重复，都不可能包含子串 B。

### 代码

```java
class Solution {
   public int repeatedStringMatch(String A, String B) {
        String a = A.repeat(2);
        String b = B.substring(0, Math.min(A.length(), B.length()));
        int i = a.indexOf(b);
        if (i < 0) return -1;

        int cnt = i > 0 ? 1 : 0;
        for (int j = 0; j < B.length(); j++) {
            if (A.charAt(i) != B.charAt(j)) return -1;
            if (i == 0) cnt++;
            i = (i + 1) % A.length();
        }

        return cnt;
    }
}
```

注意：本题的 `indexOf()` 实际运行效率取决于测试数据的复杂程度。至少，在本题解写成的时候测试字符串没有长到令`indexOf()` 的效率显著低于 KMP 算法。