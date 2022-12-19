```cpp []
class Solution {
public:
    int kthGrammar(int N, int K) {
        if (N == 1)
            return 0;
        if (K == 1 && N == 2)
            return 0;
        if (K == 2 && N == 2)
            return 1;
        if (kthGrammar(N - 1, (K + 1) / 2) == 0)
            return (K + 1) % 2;
        else
            return K % 2;
    }
};
```
