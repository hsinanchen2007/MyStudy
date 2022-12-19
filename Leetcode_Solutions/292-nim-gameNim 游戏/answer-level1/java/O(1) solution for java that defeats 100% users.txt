### 解题思路
Draw a pic of steps and whether I will win or not when it's my/his(her) turn and you'll find the pattern。
### 代码

```java
class Solution {
    public boolean canWinNim(int n) {
        if(n % 4 == 0){
            return false;
        }
        else{
            return true;
        }
    }
}
```