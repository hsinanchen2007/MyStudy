### 解题思路
此处撰写解题思路

### 代码

```java
public class Solution {
    // you need to treat n as an unsigned value
    public int hammingWeight(int n) {
        int ans = 0;
        while (n != 0) {
            n = n & (n-1);
            ans++;
        }
        return ans;
    }
}
```