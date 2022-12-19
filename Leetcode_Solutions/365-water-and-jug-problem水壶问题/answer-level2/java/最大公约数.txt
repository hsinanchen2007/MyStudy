```java
public class coding_365 {
    public boolean canMeasureWater(int x, int y, int z) {
        if (x == z || y == z || x + y == z || z == 0) {
            return true;
        }
        if (x + y < z) {
            return false;
        }
        return z == 0 || (x + y >= z && z % gcd(x, y) == 0);
    }

    int gcd(int x, int y) {
        return y == 0 ? x : gcd(y, x % y);
    }
}
```
