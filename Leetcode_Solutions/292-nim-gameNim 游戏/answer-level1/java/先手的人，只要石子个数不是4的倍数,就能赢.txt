### 解题思路
每次拿1-3个石头，要想让对方输，只要保证对方拿石头时候，石头为4的倍数就可以

### 代码

```java
class Solution {
    public boolean canWinNim(int n) {
        return n%4==0?false:true;
    }
}
```