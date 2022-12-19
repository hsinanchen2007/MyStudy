```
class Solution {
    public boolean hasGroupsSizeX(int[] deck) {
        int[] num = new int[10000];
        for (int d: deck)
            num[d]++;
        int res = -1;
        for (int n: num) {
            if (n > 0) {
                res = res == -1? n: gcd(res, n);
                if (res == 1)
                    return false;
            }
        }
        return res >= 2;
    }
    public int gcd(int a, int b) {
        return a == 0? b: gcd(b % a, a);
    }
}
```
