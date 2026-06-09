```
class Solution {
public:
    const int M = 1e9 + 7;
    int checkRecord(int n) {
        if (n == 1)
            return 3;
        if (n == 2)
            return 8;
        long A = 4; // xxxxxA
        long L = 2; // xxxxPL
        long AL = 3; // xxAxxxL
        long LL = 1; // xxxxxLL
        long ALL = 1; // xxAxxLL
        long P = 4; // xxxxxP
        long AP = 4; // xxAxxxP
        for (int i = 4; i <= n; ++i) {
            long a = L + LL + P;
            long l = P;
            long al = A + AP;
            long ll = L;
            long all = AL;
            long p = P + L + LL;
            long ap = A + AP + AL + ALL;
            A = a % M;
            L = l % M;
            AL = al % M;
            LL = ll % M;
            ALL = all % M;
            P = p % M;
            AP = ap % M;
        }
        return (A + L + AL + LL + ALL + P + AP) % M;
    }
};
```
