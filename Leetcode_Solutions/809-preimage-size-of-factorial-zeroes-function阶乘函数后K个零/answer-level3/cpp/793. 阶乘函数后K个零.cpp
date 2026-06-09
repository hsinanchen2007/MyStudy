```
class Solution {
public:
    int preimageSizeFZF(int K) {
        if(K<5)return 5;
        int s=0;
        while (s < K)
        {
            s = s*5+1;
        }

        while (K) {
            s=(s-1)/5;
            if (K / s == 5) return 0;
            K %= s;
        }
        return 5;
    }
};
```
