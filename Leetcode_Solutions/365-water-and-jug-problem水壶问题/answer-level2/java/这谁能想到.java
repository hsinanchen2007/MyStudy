### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean canMeasureWater(int x, int y, int z) {
        if(x+y<z)
            return false;
        if(x==0||y==0)
            return x==z||y==z;
        return z%gcd(x,y)==0;
    }
    
    public int gcd(int x,int y){
        return y==0?x:gcd(y,x%y);
    }
}
```