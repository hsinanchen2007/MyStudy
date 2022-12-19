### 解题思路
log(N)时间复杂度。

### 代码

```java
/* The guess API is defined in the parent class GuessGame.
   @param num, your guess
   @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
      int guess(int num); */

public class Solution extends GuessGame {
    public int guessNumber(int n) {
        int start = 1, end = n;
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (guess(mid) == 1) {
                start = mid;
            } else {
                end = mid;
            }
        }
        
        if(guess(start) == 0) {
            return start;
        }
        return end;
    }
}
```