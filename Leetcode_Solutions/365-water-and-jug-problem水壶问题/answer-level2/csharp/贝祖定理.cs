## 贝祖定理：
--a*x+b*y = m;有整数解x和y的充要条件是：m是a和b的最大公约数的倍数
public class Solution {
  public bool CanMeasureWater(int x, int y, int z)
    {
        if (x == 0 || y == 0)
        {
            if (x == z || y == z) return true;
            return false;
        }

        if (x + y < z) return false;
        return z % gcd(x, y) == 0;
    }

    int gcd(int x, int y)
    {
        if (y == 0) return x;
        return gcd(y, x % y);
    }
}