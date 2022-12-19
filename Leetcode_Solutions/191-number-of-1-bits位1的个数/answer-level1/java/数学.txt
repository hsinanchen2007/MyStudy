### 解题思路
//n 与 n-1 相与每次向右移动一位

### 代码

```java
public class Solution {
    // you need to treat n as an unsigned value
    public int hammingWeight(int n) {
        //n 与 n-1 相与每次向右移动一位
        int count = 0;
        while(n != 0){
            count += 1;
            n &= (n - 1);
        }
        return count;
    }
}
```