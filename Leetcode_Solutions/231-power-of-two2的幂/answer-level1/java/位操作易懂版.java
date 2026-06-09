### 解题思路
奇数、0、负数肯定不是2的幂（除开1）
2的幂的位长这样：1后面全是0 
如16的2进制：10000
8的位为1010

#### 思路一
判断位是1的个数

#### 思路二
位右移看有多少个1

### 代码

```java
class Solution {
    public boolean isPowerOfTwo(int n) {
        if(n<=0) return false;
        if(n==1) return true;
        if(n%2==1) return false;
        else{
             if(Integer.bitCount(n)!=1) return false;
            // while(n!=1){
            //     if(n%2==1) return false;
            //     n=n>>1;
            // }
        }
        return true;
    }
}
```