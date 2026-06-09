```
class Solution {
    public int game(int[] guess, int[] answer) {
        return (guess[0]==answer[0]?1:0) + (guess[1]==answer[1]?1:0) + (guess[2]==answer[2]?1:0);
    }
}
```
