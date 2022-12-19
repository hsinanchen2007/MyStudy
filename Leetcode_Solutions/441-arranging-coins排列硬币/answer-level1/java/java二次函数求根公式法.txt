### 解题思路
求根公式

### 代码

```java
class Solution {
    public int arrangeCoins(int n) {
        return (int)(-0.5+Math.sqrt(2*(long)n+0.25));
    }
}
```