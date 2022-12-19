### 解题思路
a 代表进位
b 代表不进位加法

### 代码

```java
class Solution {
    public int add(int a, int b) {
        while (a != 0) {
            int noCarryPlus = a ^ b  ; // 不进位加法
            a = (a & b ) << 1 ; // 进位
            b = noCarryPlus ; 
        }
        return b ;
    }
}
```