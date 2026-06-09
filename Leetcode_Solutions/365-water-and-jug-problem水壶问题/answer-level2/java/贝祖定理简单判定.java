关键在于划分成功条件。
题干默认z >= 0，首先当z = 0 时，x和y取任意值，一定成功。
当z > 0时：
- 当x + y < z时，即使两盏杯子装满水，依然不可能成功。
- 当x + y = z时，x, y, z取任意值，一定成功。
- 当x + y > z时，不一定。问题的核心在此，用贝祖定理判定成功条件。
由贝祖定理可知，对任何整数x、y和它们的最大公约数gcd(x, y)，对于它们的的任意整数倍数a,b,c，都有
ax + by = c·gcd(x, y)恒成立。
由题干给出的几种操作，要完成目标，一定有ax + by = z。
和贝祖定理完美锲合，那么，只要z % (gcd(x, y)) = 0为真，则一定成功。
```Java
class Solution {
    //贝祖定理
    public static boolean canMeasureWater(int x, int y, int z) {
        //默认z >= 0
        if (z == 0)
            return true;
        //z>0
        if (x +y <z)
            return false;
        else if (x + y == z)
            return true;
        else
            //only consider: x!=0,y!=0; x!=0,y==0; x==0,y!=0
            return z % gcd(x, y) == 0;
    }
    private static int gcd(int x, int y) {
        while (y != 0) {
            int temp = y;
            y = x % y;
            x = temp;
        }
        return x;
    }
}
```
提交记录：
执行用时：0 ms
内存消耗：36.8 MB
