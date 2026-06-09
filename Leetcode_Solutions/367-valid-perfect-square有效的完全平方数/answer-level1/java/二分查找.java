### 代码

```java
class Solution {
    public boolean isPerfectSquare(int x) {
        if (x < 2) {
            return true;
        }
        long start = 2;
        long end = x / 2;
        
        while (start <= end) {
            long middle = start + (end - start) / 2;
            long num = middle * middle; 
            if (num == x) {
                return true;
            } else if (num > x) {
                end = middle - 1;
            } else {
                start = middle + 1;
            }
        }
        return false;
    }
}
```