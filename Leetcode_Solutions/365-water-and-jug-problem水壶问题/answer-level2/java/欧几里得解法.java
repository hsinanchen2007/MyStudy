### 解题思路

这道题死来想去都不知道怎么入手，看了看标签是数学，自己数学又不好，看了看官方解法，太秀了吧，只是借用了一下官方代码签到到，至于如果证明过程，移步大神。

### 代码

```java
class Solution {

    public boolean canMeasureWater(int x, int y, int z) {
        if(x + y < z){
            return false;
        }else if(x == 0 || y == 0){
            return z == 0 || x + y == z;
        }else{
            return z % gcd(x ,y) == 0;
        }
    }

    public int gcd(int m, int n){
        int mod;
        while(n!=0){
            mod = m % n;
            m=n;
            n=mod;
        }
        return m;
    }
}
```