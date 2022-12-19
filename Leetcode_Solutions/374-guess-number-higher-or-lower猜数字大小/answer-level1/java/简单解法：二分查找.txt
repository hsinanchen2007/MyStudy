```
public class Solution extends GuessGame {
    public int guessNumber(int n) {
        int l = 1; 
        int r = n;
        int mid;
        
        while(l <= r) {
            mid = l + ((r - l) >> 1);
            int val = guess(mid);
            if(val > 0) {
                l = mid + 1;
            } else if(val < 0) {
                r = mid - 1;
            }else {
                return mid;
            }
        }
        return 0;
    }
}
```
