### 解题思路
很基本的二分查找题型。要注意减少函数guess()的调用，否则耗时会增加。即不要在每个if-else判断中调用一次guess()，而是在每次循环都用一个变量cmp记录下函数调用的结果，否则一次循环函数调用次数为2次。

### 代码

```java
/* The guess API is defined in the parent class GuessGame.
   @param num, your guess
   @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
      int guess(int num); */

public class Solution extends GuessGame {
    public int guessNumber(int n) {
        int lo=1,hi=n;
        while(lo<=hi)
        {
            int mid=lo+(hi-lo)/2;//防止溢出的写法
            int cmp=guess(mid);//为了减少函数的调用次数
            if(cmp>0)       lo=mid+1;
            else if(cmp<0)  hi=mid-1;
            else            return mid;     
        }
        return -1;
    }
}
```