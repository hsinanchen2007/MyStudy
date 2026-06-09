### 解题思路
2的幂次方，将十进制转换为二进制时有且只有1个1，使用（n & (n -1)）与运算判断是否等于0即可

### 代码

```java
class Solution {
    public boolean isPowerOfTwo(int n) {
        if((n > 0) && ((n & (n - 1)) == 0)){
            return true;
        }
        return false;
    }
}
```