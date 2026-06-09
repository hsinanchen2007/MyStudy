### 解题思路
贝祖数
### 代码

```java
class Solution {
    public boolean canMeasureWater(int x, int y, int z) {
        if(x+y<z) return false;
        if(x==0 || y==0){
            return z==0 || x+y==z;
        }
        //贝祖定理 ax+by=z z一定是x和y的最大公约数的倍数
        int a = Math.max(x,y);
        int b = Math.min(x,y);
        while(b!=0){
            int temp = a%b;
            a = b;
            b = temp;
        }
        if(z%a==0){
            return true;
        }
        return false;
    }
}
```