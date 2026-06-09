### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int game(int[] guess, int[] answer) {
        int sum = 0;
        for(int i=0, len = guess.length; i<len; ++i){
            sum += guess[i] == answer[i] ? 1 : 0;
        }
        return sum;
    }
}
```