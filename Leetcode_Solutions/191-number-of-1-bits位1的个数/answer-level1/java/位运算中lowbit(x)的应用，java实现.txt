### lowbit公式
lowbit公式：`x & -x`。
作用是可以在常数时间找出数字n中最后一个1出现的位置。
举个例子：
```java
例如n = 10。用二进制表示就是1010，而它的负数-10用二进制补码表示则为0110，
取&后得到的结果为10，这就得到了n最后一个1出现的位置对应的数字。
可以试着证明一下，这里就不写了。
```
### 题解
知道lowbit公式后，这个题目就非常简单了。每次通过lowbit公式找到最后一个1对应的数，然后将它减去，直到n为0为止。统计减法操作的次数即可。
```java
public class Solution {
    // you need to treat n as an unsigned value
    public int hammingWeight(int n) {
        int ans = 0;
        while(n != 0) {
            ans++;
            n -= lowbit(n);
        }
        return ans;
    }
    
    private int lowbit(int x) {
        return x & -x;
    }
}
```