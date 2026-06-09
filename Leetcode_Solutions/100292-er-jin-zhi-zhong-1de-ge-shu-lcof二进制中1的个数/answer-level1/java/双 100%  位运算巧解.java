### 解题思路


### 代码

```java
public class Solution {
    // you need to treat n as an unsigned value
    public int hammingWeight(int n) {
          int count=0;
        for (int i = 0; i < 32; i++) {
            if ((n&(1<<i))==(1<<i)){count++;}
        }
        return count;
    }
}
```