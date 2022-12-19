### 解题思路
由于对位的修改只会影响1<<base位
对于m,n,当两数相差2^n时，则第n位肯定为0，那么：
    1） 当第n位为1，修改为0
    2） 当第n位为0，不变
最后使用res >= (1<<base) && result > 0 && m > 0剪枝

### 代码

```java
class Solution {
    public int rangeBitwiseAnd(int m, int n) {
        if(m == n || m == 0) return m;
        int res = n - m;
        int result = m;
        int base = 0;
        while(res >= (1<<base) && result > 0 && m > 0){
            //int temp = result ^ (1<<base);            
            //result = result & (1<<base);
            if(((result >>> base) & 1) == 1) result ^= 1<<base;
            m = m >>> 1;
            base++;
        }
        return result & n;
    }
}
```