```
class Solution {
    public int lastRemaining(int n) {
        return core(n, n, 1, true);
        
    }
    private int core(int lastnum, int n, int step, boolean l2r) {
        if (n==1) return lastnum;
        if (n==2) {
            if (l2r) return lastnum;
            else return lastnum-step;
        }
        if (n==3) return lastnum-step;
        int newnum=lastnum - step, newn=n/2, nstep=step*2;
        if (n%2==0&&l2r) {
            newnum = lastnum;
        }

        return core(newnum, newn, nstep, !l2r);
    }
}
```
