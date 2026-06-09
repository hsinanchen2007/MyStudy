### 解法一：
循环位移，取出每一位，计数并返回。

代码：
```java
public class Solution {
    // you need to treat n as an unsigned value
    public int hammingWeight(int n) {
        int cnt = 0;
        for(int i = 0; i < 32; i++)
            if((n >> i & 1) == 1)
                cnt++;
        return cnt;
    }
}
```

### 解法二：
不断消去二进制码中的1，直至二进制码变为0，记录消去的1的个数。
具体做法：
**一个数n与(n-1)做按位与，可消去n的二进制码中最低位的1**。

代码:
```java
public class Solution {
    // you need to treat n as an unsigned value
    public int hammingWeight(int n) {
        int cnt = 0;
        while(n != 0)
        {
            n &= (n - 1);
            cnt++;
        }
        return cnt;
    }
}
```