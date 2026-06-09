bfs的问题先没看，采用了gcd求最大公约数的做法，如果z能整除x和y的最大公约数，就可以刚好装下z，具体证明还没研究。

### 代码

```java
class Solution {
    public boolean canMeasureWater(int x, int y, int z) {
        if( z == 0) return true;
        if(x + y < z)   return false;

        int big = Math.max(x, y);
        int small = x + y - big;
        if(small == 0) return big == z;

        while(big % small != 0){
            int temp = small;
            small = big % small;
            big = temp;
        }

        return z % small == 0;
    }
}
```