### 解题思路
1.典型的二分法，此处是关于二分法的几个问题
2.为什么不用mid=left+right，因为会溢出，溢出是指计算机里面按照二进制来做，所得出的数很可能超出计算机能承受的范围
3，最后的return，return什么都行吗？可以试试这个return

### 代码

```java
/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

public class Solution extends GuessGame {
    public int guessNumber(int n) {
        int left=1;
        int right=n;
        while(left<right)
        {
            int mid=left+(right-left)/2;
            if(guess(mid)==1)
            {
                 left=mid+1;  
            }
            else if(guess(mid)==-1)
            {
              right=mid-1;
            }
            else
            {
                return mid;
            }

          
        }
          return right;
    }
}
```