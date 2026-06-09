### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean canMeasureWater(int x, int y, int z) {
        if(x + y < z){
            return false;
        }
        if( x == z || y == z || x + y == z){
            return true;
        }
        return z%(GCD(x,y)) == 0;
    }
    
    public int GCD(int a, int b){
        while (b != 0){
            int temp = b;
            b = a%b;
            a = temp;
        }
        return a;
    }
}
```