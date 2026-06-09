### 解题思路
这是你逼我的

### 代码

```java
class Solution {
    public int sumNums(int n) {
        int res = n == 0 ? 0 : sumNums(n - 1) + n;
        return res;
    }
}
```