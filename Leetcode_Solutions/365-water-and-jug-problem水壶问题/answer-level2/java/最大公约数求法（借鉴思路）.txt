本题思路借鉴了一下LetLifeStop大佬使用C++实现的想法，感觉最大公约数的解法甚是巧妙。
我使用了Java语言实现了以下。
采用欧几里得算法求出 x 与 y 的最大公约数，再对x = 0,y = 0的情况进行特殊判定即可。

```
class Solution {
    public boolean canMeasureWater(int x, int y, int z) {
        if(x == 0 && y == 0) return z == 0;
        return z == 0 || (z % gcd(x,y) == 0 && x + y >= z);
    }
    
    static int gcd(int x,int y){
        if(y == 0) return x;
        int r = x % y;
        return gcd(y,r);
    }
}
```

再次感谢LetLifeStop大佬提供的思路。
