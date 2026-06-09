### 解题思路
用的是数学的方法，求最大公约数

### 代码

```java
class Solution {
    public boolean canMeasureWater(int x, int y, int z) {
        if(z == 0)return true;
        if(x + y < z)return false;
        if(x < y){
            int tmp = x;
            x = y;
            y = tmp;
        }
        if(y == 0){
            return x == z;
        }
        int gcd = getgcd(x, y);
        return z%gcd == 0;
    }

    public int getgcd(int x, int y){
        while(x != y){
            int tmp = x % y;
            if(tmp == 0)return y;
            x = y;
            y = tmp;
        }
        return x;
    }
}
```