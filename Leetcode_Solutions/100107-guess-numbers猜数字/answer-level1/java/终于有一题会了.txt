### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int game(int[] guess, int[] answer) {
        int cnt = 0;
        for(int i = 0; i < 3; i++){
            if(guess[i] == answer[i]){
                cnt++;
            }
        }
        return cnt;
    }
}
```