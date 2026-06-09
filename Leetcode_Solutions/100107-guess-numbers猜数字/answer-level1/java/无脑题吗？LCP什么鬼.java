### 解题思路
不知道这个题是干嘛的，正好搜索到。无语

### 代码

```java
class Solution {
    public int game(int[] guess, int[] answer) {
        int res = 0;
        for (int i = 0 ; i < guess.length; i++) {
            if(guess[i] == answer[i]) res++;
        }
        return res;
    }
}
```