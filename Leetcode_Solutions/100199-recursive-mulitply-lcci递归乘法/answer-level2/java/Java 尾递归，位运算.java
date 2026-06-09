### 解题思路
尾递归，位运算。

思路：
```java
偶数为循环次数的运算过程
8 * 9 
4 * 18
2 * 36
1 * 72
72

奇数为循环次数的运算过程
7 * 9
9 + (3 * 18)        // 7/2 时丢失一个 9 
9 + 18 + (1 * 36)   // 3/2 时丢失一个 18 
9 + 18 + 36 
63
```
![image.png](https://pic.leetcode-cn.com/81d9c09d742bc615d2a4aa8e343f13c227e55241eaf2873f6c12bf35512372ae-image.png)

### 代码

```java
class Solution {

    public int multiply(int A, int B) {
        return (A < B) ? multiply2Help(A, B, 0) : multiply2Help(B, A, 0); // 寻找最小循序次数
    }

    // missPart 为奇数除以 2 时丢失的部分
    public int multiply2Help(int A, int B, int missPart) {
        if (A < 2) return missPart + B;   // 最终结果 = 丢失的部分 + 最终 B 的结果
        missPart += (A & 1) == 1 ? B : 0; // 是否为奇数，奇数时记录丢失的部分
        return multiply2Help(A / 2, B << 1, missPart);
    }
}
```