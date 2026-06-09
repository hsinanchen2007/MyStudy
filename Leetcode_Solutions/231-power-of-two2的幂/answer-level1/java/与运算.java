### 解题思路
利用数字的二进制特点
2的幂次方的二进制只有最高位是 1，其余位都是0，比它小 1 的数则刚好相反都是1，当然也可以说最高位是0


### 代码

```java
class Solution {
    public boolean isPowerOfTwo(int n) {
        return n>0 &&  (n&n-1)==0;
    }
}
```