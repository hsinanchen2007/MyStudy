### 解题思路
只要n>2，并且n % 2== 0，那么就往右移一位，如果下一次发现，n % 2!=0 ,就可以直接返回false了。
最后只需要判断 n是否等于2

### 代码

```java
class Solution {
    public boolean isPowerOfTwo(int n) {
        if(n == 1 || n == 2)
            return true;
        while (n > 2){
            if(n % 2 == 0)
                n = n >> 1;
            else
                return false;
        }
        return (n == 2);
    }
}
```