```
import java.util.*;
class Solution {


    public int nthUglyNumber(int n, int a, int b, int c) {
        int left = 0;
        int right = Integer.MAX_VALUE;
        long ab_mcm = mcm(new int[]{a, b});
        long ac_mcm = mcm(new int[]{a, c});
        long bc_mcm = mcm(new int[]{b, c});
        long abc_mcm = mcm(new int[]{a, b, c});
        return nthUglyNumber(n, a, b, c, left, right, ab_mcm, ac_mcm, bc_mcm, abc_mcm);
    }

    private int nthUglyNumber(int n, int a, int b, int c, long left, long right, long ab_mcm, long ac_mcm, long bc_mcm, long abc_mcm) {
        long center = (left + right) / 2;
        long uglyNumberBefore = center / a + center / b + center / c - center / ab_mcm - center / ac_mcm - center / bc_mcm + center / abc_mcm;
        if (uglyNumberBefore > n) {
            return nthUglyNumber(n, a, b, c, left, center - 1, ab_mcm, ac_mcm, bc_mcm, abc_mcm);
        } else if (uglyNumberBefore < n) {
            return nthUglyNumber(n, a, b, c, center + 1, right, ab_mcm, ac_mcm, bc_mcm, abc_mcm);
        } else {
            return (int) (center - Math.min(Math.min(center % a, center % b), center % c));
        }
    }

    //mcm
    public long mcm(int[] arr) {
        long mcm = mcm(arr[1], arr[0]);
        for (int i = 2; i < arr.length; i++)
            mcm = mcm(mcm, arr[i]);
        return mcm;
    }

    private long mcm(long a ,long b) {
       return a*b/gcd(a,b);
    }

    //gcd
    private long gcd(int[] arr) {
        long gcd = gcd(arr[1], arr[0]);
        for (int i = 2; i < arr.length; i++)
            gcd = gcd(gcd, arr[i]);
        return gcd;
    }

    private long gcd(long a, long b) {
        long max = Math.max(a, b);
        long min = Math.min(a, b);
        if (max % min == 0) return min;
        return gcd(min, max % min);
    }
}
```
