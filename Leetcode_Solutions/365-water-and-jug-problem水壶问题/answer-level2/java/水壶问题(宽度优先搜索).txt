### 解题思路
数学方法

### 代码

```java
class Solution {
    public boolean canMeasureWater(int x, int y, int z) {
        if (x + y < z) return false;
        if (x == 0 || y == 0) return z == 0 || x + y == z;
        return z % gcd(x, y) == 0;
    }
    public int  gcd(int a,int b)
    {
        int r;
        while(b>0)
        {
             r=a%b;
             a=b;
             b=r;
        }
        return a;
    }
}
```