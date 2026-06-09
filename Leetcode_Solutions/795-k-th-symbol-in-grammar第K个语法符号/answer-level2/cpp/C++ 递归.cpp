### 解题思路
Grammar的每一行长度是上一行的2倍，
第N行的第K个符号，由第N-1行的第(K+1)/2个符号扩展后得到
### 代码

```cpp
class Solution {
public:
    int kthGrammar(int N, int K) {
        if (K == 1) {
            return 0;
        }
        int pre = kthGrammar(N - 1, (K + 1) / 2);
        int mod = K % 2;
        if (mod == 1) {
            return pre;
        }
        return pre == 0 ? 1 : 0;
    }
};
```