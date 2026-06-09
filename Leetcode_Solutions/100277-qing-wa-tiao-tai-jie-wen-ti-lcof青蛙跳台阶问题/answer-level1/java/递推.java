### 解题思路
找规律的话，后面的种数是前面两种之和，注意特殊考虑n=0的情况，dp也是一样的吧，反之这样是双百，可能有些人懒得提交

### 代码

```java
class Solution {
    public int numWays(int n) {
         if (n == 0 || n == 1) return 1;
        if (n == 2) return 2;
        int i1 = 1;
        int i2 = 2;
        for (int i = 3; i <= n; i++) {
            int temp = (i1 + i2) % 1000000007;
            i1 = i2;
            i2 = temp;
        }
        return i2;
    }
}
```