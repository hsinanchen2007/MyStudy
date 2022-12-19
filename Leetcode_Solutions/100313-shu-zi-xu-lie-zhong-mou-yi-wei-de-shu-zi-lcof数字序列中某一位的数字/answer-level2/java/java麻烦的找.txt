```
class Solution {
    public int findNthDigit(int n) {
        if(n < 10) {
            return n;
        }
        int sn = 1;
        int cnt = 0;
        int start = 0;
        int pre = start;
        while(n > start) {
            cnt++;
            pre = start;
            sn *= 10;
            start += 9 * Math.pow(10, cnt - 1) * cnt;
        } 
        start = pre + 1;
        sn /= 10;

        int cur = sn + (n - start) / cnt;
        int curB = n - (start + cnt * ((n - start) / cnt) - 1);

        for(int i = 0; i < cnt - curB; i++) {
            cur /= 10;
        }
        return cur % 10;

    }
}
```
