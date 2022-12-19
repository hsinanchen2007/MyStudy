### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean canMeasureWater(int x, int y, int z) {
        /*
        因此，我们可以认为每次操作只会给水的总量带来 x 或者 y 的变化量。
        因此我们的目标可以改写成：找到一对整数 a,b，使得ax+by=z 
        而贝祖定理告诉我们，ax+by=z 有解当且仅当 z 是 x,y 的最大公约数的倍数。
        因此我们只需要找到 x,y 的最大公约数并判断 z 是否是它的倍数即可。
        */
        if(z == 0) return true;
        if(x + y < z) return false;
        int i = gcd(x, y);
        return z % i == 0? true : false;
    }
    public int gcd(int a, int b){
        return b == 0? a : gcd(b, a % b);
    }
}
```