```java
class Solution {
    int N;
    double[][] mem;
    public double soupServings(int N) {
        this.N = N;
        if (N > 5000) return 1.0;
        mem = new double[N + 1][N + 1];
        return helper(N, N);
    }

    public double helper(int A, int B) {
        if (A <= 0 && B <= 0) return 0.5;
        if (A <= 0) return 1.0;
        if (B <= 0) return 0.0;
        if (mem[A][B] > 0.0) return mem[A][B];
        int[] l = new int[]{100, 75, 50, 25};
        int[] r = new int[]{0, 25, 50, 75};
        for (int k = 0; k < l.length; k ++) {
            mem[A][B] += 0.25 * helper(A - l[k], B - r[k]);
        }
        return mem[A][B];
    }   
}
```