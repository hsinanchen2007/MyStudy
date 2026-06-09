### 解题思路
此处撰写解题思路

### 代码

```java
/* The guess API is defined in the parent class GuessGame.
   @param num, your guess
   @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
      int guess(int num); */

public class Solution extends GuessGame {
    public int guessNumber(int n) {
        if (n == 0) return -1;
        int left = 1;
        int right = n;
        while (left < right) {
            int mid = (left + right) >>> 1;
            //这里1的意思是mid的值比要猜的值小，所以说成：我的数字比较大
            if (guess(mid) == 1) {
                //下一个区间是：[mid+1, right]
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
}
```