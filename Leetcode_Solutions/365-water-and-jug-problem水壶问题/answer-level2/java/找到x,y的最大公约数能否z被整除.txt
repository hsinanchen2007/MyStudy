### 解题思路
找到x,y的最大公约数能否z被整除

### 代码

```java
class Solution {
    public boolean canMeasureWater(int x, int y, int z) {
        boolean b1= false;
        boolean b2= false;
        boolean b3= false;
        if(z==0) {
            return true;
        }
        if(x+y<z) {
            return false;
        }
        if (x==0) {
            return z==y;
        }
        if(x>y) {
            int c = x;
            x = y;
            y = c;
        }
        while (y%x!=0) {
            int c = y;
            y = x;
            x = c%x;
        }
        return z%x==0;
        
    }
}
```