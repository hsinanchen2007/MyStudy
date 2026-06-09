### 代码

```java
class Solution {
  public boolean canMeasureWater(int x, int y, int z) {
        return z == 0 || (x+y >= z && z%gcd(x,y) == 0);
    }

    public int gcd(int a, int b){
        return b == 0 ? a:gcd(b, a%b);
    }
}
```