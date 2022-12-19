### 解题思路
事实上，这就是一道脑筋急转弯的题目，当给定的n为4的倍数时，先手的人是一定赢不了的，这个游戏要赢只需要在石头的数量控制为4的倍数时再让对手选择，自己就能赢。

### 代码

```java
class Solution {
    public boolean canWinNim(int n) {
        if(n>=1 && n<=3){
            return true;
        }else if(n%4 == 0){
            return false;
        }else{
            return true;
        }
    }
}
```