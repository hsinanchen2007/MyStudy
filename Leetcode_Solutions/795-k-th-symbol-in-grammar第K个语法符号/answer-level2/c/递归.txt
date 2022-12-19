**递归求解**

示例
第一行: 0
第二行: 01
第三行: 0110
第四行: 01101001

从示例中能看到，前一行和后一行的前一半相同，和后一半相反，通过这个关系，能从后面不断向前寻找到和第一行0的关系。

有几种情况
1. N = 1, 只有0;
2. N > 1, K 位于数列的前一半，其结果kthGrammar(N, K) = kthGrammar(N - 1, K);
3. N > 1, K 位于数列的后一半，和前一半相反，其结果kthGrammar(N, K) = 1 ^ kthGrammar(N - 1, K - length/2); length = 1 << (N - 1); 即 kthGrammar(N, K) = 1 ^ kthGrammar(N - 1, K - (1 << (N - 2)));

**因此代码如下。**

```
int kthGrammar(int N, int K){
    if (N == 1) {
        return 0;
    }
    if (K <= 1 << (N - 2)) {
        return kthGrammar(N - 1, K);
    } else {
        return 1 ^ kthGrammar(N - 1, K - (1 << (N - 2)));
    }
}
```
