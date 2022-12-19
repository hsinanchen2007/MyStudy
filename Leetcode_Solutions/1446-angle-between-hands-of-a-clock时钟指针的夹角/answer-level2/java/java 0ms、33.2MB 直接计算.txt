x时y分的夹角为：5.5y-30x , 当夹角大于180度的时候，用360减一下就行了
```
class Solution {
   public double angleClock(int hour, int minutes) {
        double a = Math.abs(5.5 * minutes - 30 * hour);
        if(a > 180) {
            return 360 - a;
        }
        return a;
    }
}
```
