复杂度O(1)
```
class Solution {
    public int insertBits(int N, int M, int i, int j) {
        int t = N % (1<<i);
        N >>>= (j+1);
        N <<= (j-i+1);
        N += M;
        N <<= i;
        N += t;
        return N;
    }
}
```

