### 解题思路
判断转换后的int是否和long类型的结果是否一致

### 代码

```java
class Solution {
    public int reverse(int x) {
        
         long r = 0;
        for (int i = x; i != 0; i /= 10) {
            r *= 10;
            r += x % 10;
            x /= 10;
        }
        if ((int) r == r){
            return (int)r;
        }else {
            return 0;
        }
    }
}
```