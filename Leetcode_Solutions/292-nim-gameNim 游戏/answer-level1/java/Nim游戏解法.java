### 解题思路
只要剩下的石头是4的倍数，那么谁先拿谁输。所以只要石头数不是4的倍数，先拿者可以拿走1~3个石头使剩下的石头成为4的倍数，赢得游戏。

### 代码

```java
class Solution {
    public boolean canWinNim(int n) {
        return n%4!=0;
    }
}
```