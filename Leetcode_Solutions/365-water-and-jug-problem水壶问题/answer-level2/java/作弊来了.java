### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean canMeasureWater(int x, int y, int z) {
        if(x == 0 || y== 0){
            if(x == z || y ==z) return true;
            return false;
        }
        //特判：x +y < z 时一定是false
        if(x+y < z) return false;

        int tmp = gcd(x,y);
        return z % tmp == 0;

    }

    public int gcd(int x, int y){
        if(y == 0) return x;
        return gcd(y,x%y);
    }
}
```