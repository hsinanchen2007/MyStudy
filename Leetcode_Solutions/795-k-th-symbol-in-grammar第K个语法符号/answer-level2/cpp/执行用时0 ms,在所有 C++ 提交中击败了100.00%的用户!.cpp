### 代码

```cpp
class Solution {
public:
    int kthGrammar(int N, int K) {
        int count = 0;
        for (K = K - 1; K > 0; K &= K - 1) {
            count = !count;
        }
        return count;
    }
};
```