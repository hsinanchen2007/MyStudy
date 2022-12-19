执行用时 : 1 ms, 击败了97.99% 的用户。
内存消耗 : 32.3 MB, 击败了84.05% 的用户。
```
public class Solution extends GuessGame {
    public int guessNumber(int n) {
        int l = 1;
        int r = n;
        if(guess(l) == 0){
            return l;
        }
        if(guess(r) == 0){
            return r;
        }
        while(l!=r){
            int m = l + (r-l) / 2;
            int res = guess(m);
            if(res == 0){
                return m;
            }else if(res < 0){
                r = m;
            }else{
                l = m;
            } 
        }
        return l;
    }
}
```