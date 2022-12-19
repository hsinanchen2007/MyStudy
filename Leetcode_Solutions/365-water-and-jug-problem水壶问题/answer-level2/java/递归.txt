### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    
    private int x;
    private int y;
    private int z;

    public boolean canMeasureWater(int x, int y, int z) {
        this.x = Math.min(x, y);
        this.y = Math.max(x, y);
        this.z = z;
        if (x+y < z)
            return false;
        if (x==z || y==z || x+y==z || x+x==z || y-x==z)
            return true;


        return helperII(this.y-this.x);
    }

    private boolean helperII(int water) {
        //System.out.print(water);

        if (water <= 0)
            return false;

        if (water == z)
            return true;

        if (water+x==z)
            return true;

        if (x<=water && water<y) {
            if (water-x == z)
                return true;
            return helperII(water-x);
        }

        if (water <x) {
            if (water + y == z || (y - x + water) == z)
                return true;
            return helperII(y-x+water);
        }
        return false;
    }
}
```