### 解题思路

### 代码

```java
class Solution {
    public int mySqrt(int x) {
        // r初始为x, 很有可能会溢出！sqrt(Integet.MAX_VALUE)=46340
        int r = Math.min(x, 46340);
        while(r * r > x){
            r = (r + x / r) / 2;
        }
        return r;
    }
}
```