### 解题思路
寻找最大公约数

### 代码

```java
class Solution {
     public boolean canMeasureWater(int x, int y, int z) {
        if (x + y < z) return false;
         if(x+y==z) return true;
        int n = gcd(x, y);
        if (n!=0 && z % n == 0) return true;
        else return false;
    }

    public int gcd(int a, int b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }
 
}
```