类似官方题解3，但是官方题解并不容易理解，这里说下我的理解方式。
其实可以把递推方式拆成两种，一种是从0开始，另一种是从1开始。下面举个例子
从0开始：
```
0
01
0110
01101001
```

从1开始：
```
1
10
1001
10010110
```

可以看出，如果 K 小于等于 所在行的一半，也就是`2^N-2`，那么直接去上一行找，也就是下面的`helper(N-1, K, flag)`;
反之，要从后半部分找，而后半部分，正是01翻转后的前一行，也就是`helper(N-1, K - half, 1-flag)`。
这里 flag 是0或1，来回翻转。
```c++
class Solution {
public:
    int kthGrammar(int N, int K) {
        return helper(N, K, 0);
    }

    int helper(int N, int K, int flag) {
        if (N == 1) return flag;
        int half = (1 << (N-2));
        if (K <= half) {
            return helper(N-1, K, flag);
        } else {
            return helper(N-1, K - half, 1-flag);
        }
    }
};
```