### 解题思路
纯数学 我不懂啊

### 代码

```java
class Solution {
     public boolean canMeasureWater(int x, int y, int z) {
        if(x+y<z){
            return false;
        }
        if(x == 0 || y == 0){
            return z==0 || x+y==z;
        }
        return z % gcb(x,y) == 0;
    }
    int gcb(int m, int n) {  
            if (m < n) { 
                int temp = m;  
                m = n;  
                n = temp;  
            }  
            if (m % n == 0) {  
                return n;  
            } else {  
                return gcb(n, m % n);  
            }  
      } 
}
```