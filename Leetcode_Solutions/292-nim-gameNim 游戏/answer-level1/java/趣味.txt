### 解题思路
只要避免你取的时候石子是4的倍数就可

### 代码

```java
class Solution {
    public boolean canWinNim(int n) {
        if(n%4==0)
            return false;
        else
            return true;
    }
}
```