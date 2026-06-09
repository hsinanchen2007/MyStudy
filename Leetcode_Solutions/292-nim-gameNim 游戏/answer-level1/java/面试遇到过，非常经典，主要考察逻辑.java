### 解题思路
四个一组，要想办法去凑4

### 代码

```java
class Solution {
    public boolean canWinNim(int n) {
        if(n%4==0){
            return false;
        }else{
            return true;
        }

    }
}
```