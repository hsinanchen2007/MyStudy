### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int game(int[] guess, int[] answer) {
       int count = 0;
       for(int i=0;i < guess.length;i++){
           if(guess[i] == answer[i])
                count++;
       }
       return count;
    }
}
```