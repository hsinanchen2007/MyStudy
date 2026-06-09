```
class Solution {
    public int game(int[] guess, int[] answer) {
        int ans = 0;
        for (int i = 0; i < guess.length; i++) if (guess[i] == answer[i]) ans++;
        return ans;
    }
}
```
