### 解题思路
异或操作算出低位，与操作+左移一位算出进位，低位+进位，此时又是一个加法，继续刚刚的操作，把低位和进位分别当场a和b，不断循环，直到进位是0，这个时候，之前的异或操作就相当于是无进位的加法了

### 代码

```java
class Solution {
    public int getSum(int a, int b) {
        if(a == 0){
            return b;
        }
        if(b == 0){
            return a;
        }
        int lower = 0;
        int carrier = 0;
        while(true){
            // 异或操作，相同为0，不同为1
            lower = a^b;
            carrier = a&b;
            if (carrier==0) break;
            a = lower;
            b = carrier<<1;
        }
        return lower;
    }
}
```