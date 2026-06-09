### 解题思路
和前面3的幂是一样的解题思路。

### 代码

```java
class Solution {
    public boolean isPowerOfFour(int num) {
        if(num <= 0)
            return false;
        if(num == 1)
            return true;
        
        if(num % 4 != 0)
            return false;
        else
            return isPowerOfFour(num/4);
    }
}
```