# 方法：递归
思想
- 父节点位置：（k+1）/2
- 当父节点是0，k是偶数（k%2=0），对应的值为0；
- 当父节点是0，k是奇数（k%2=1），对应的值为1；
- 当父节点是1，k是偶数（k%2=0），对应的值为1；
- 当父节点是1，k是奇数（k%2=1），对应的值为0；

```java []
class Solution {
    public int kthGrammar(int N, int K) {
        if (N == 1) return 0;
        
        int value = kthGrammar(N-1, (K+1)/2);
        
        return (value == 0) ? ((K&1) == 0 ? 1 : 0) : ((K&1) == 0 ? 0 : 1);
    }
}
```

进一步改进：
- 第 K 位的父位应该是第 (K+1) / 2 位;
- 如果父位是 0，那么这一位就是 1 - (K%2);
- 如果父位是 1，那么这一位就是 K%2。
```java []
class Solution {
    public int kthGrammar(int N, int K) {
        if (N == 1) return 0;
        
        int value = kthGrammar(N-1, (K+1)/2);
        
        return (value == 0) ? (1- K%2) : (K%2);
    }
}
```


再进一步改进：
- 父节点位置：（k+1）/2
- 当k是奇数（k%2=1），父节点值为1时，k对应的值为1；
- 当k是偶数（k%2=0），父节点值为0时，k对应的值为0；
- 当k是奇数（k%2=1），父节点值为0时，k对应的值为0；
- 当k是偶数（k%2=0），父节点值为1时，k对应的值为1；
-  总结：相同为1，不同为0; 正好和“异或”^相反，所以对k取反，再&1，判断位置奇偶性，再与父节点的值异或，即可得当前值.

```java []
class Solution {
    public int kthGrammar(int N, int K) {
        if (N == 1) return 0;
        return (~K & 1) ^ kthGrammar(N-1, (K+1)/2);
    }
}
```
复杂度分析

- 时间复杂度：O(N)。找出答案需要 N−1 步。

- 空间复杂度：O(1)。 

# 方法2 ： 递归（翻转）

- 后半部分总是与前半部分相反，也就是说：'0' 变成 '1' 而 '1' 变成 '0'。
- 思想：如果 K 在后半部分，那么我们可以将 K -= (1 << N-2) 设为前半部分，然后翻转得到最终答案。

- 第 N 行对应的位数是 2 的 N-1 次方, 即 1 << N-1；
- 则前半部分最后一位的位数为 1 << N-2；
- 如果 K <= 1 << N-2， 则直接读取上一行的 K 位置即可；
- 否则，读取未翻转前K对应的位置 （K - (1 << N-2)) 上的值，然后取反即可；

```java []
class Solution {
    public int kthGrammar(int N, int K) {
        if (N == 1) return 0;

        // midPos = 1 << N-2
        if (K <= 1 << N-2)
            return kthGrammar(N-1, K);

        return kthGrammar(N-1, K - (1 << N-2)) ^ 1;
    }
}
```