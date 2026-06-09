```
class Solution {
    public int subtractProductAndSum(int n) {
        int tmp = n;
        int p = 1;
        while(tmp >= 1) {
            p *= tmp % 10;
            tmp /= 10;
        }

        tmp = n;
        int s = 0;
        while(tmp >= 1) {
            s += tmp % 10;
            tmp /= 10;
        }

        return p - s;
    }
}
```
