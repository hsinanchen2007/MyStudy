```
class Solution {
public:
    int kthGrammar(int N, int K) {
        return bitset<32>(K-1).count()%2;
    }
};
```
