两个数组默认了是等长的，所以取其中一个长度就可以了。
```
class Solution {
    public int game(int[] guess, int[] answer) {
        int count = 0;
        int m = guess.length;
        for(int i = 0; i < m;i++){
            if(answer[i] == guess[i])
            count++;
        }
        return count;
    }
}
```
