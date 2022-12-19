### 解题思路
  与：有0出0，全1为1。
  不断把数字的最后一个1反转 n &= (n-1)

### 代码

```java
public class Solution {
    // you need to treat n as an unsigned value
   public int hammingWeight(int n) {
       int sum = 0;
       while(n != 0){
           sum++;
           n &= (n-1);
       }
       return sum;
    }
}
```