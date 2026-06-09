```c++
class Solution {
public:
    int bitwiseComplement(int N) {
      if (N == 0) return 1;
      for (int i = 0; i < 31; i++) {
        if ((1 << i) > N) break;
        N ^= (1 << i);
      }
      return N;
    }
};
```