一 算法分析与设计
（一）分析
对X执行乘2操作相当于对Y（Y需是偶数）执行除2操作，对X执行减一操作相当于对Y执行加一操作。
当X > Y时，因X乘2只会使X更大，故应连续执行减一操作，需要X-Y次。
当X < Y时，若Y是偶数是，因Y先执行两次加一操作,再执行一次除2操作（Y+2）/2,与Y先执行一次除2操作，再执行一次加一操作Y/2 + 1效果一样，但前者需3步，后者只需两步，根据贪心策略，应优先选择后者；
若Y是奇数时，应先对Y执行加一操作，使其变为偶数，之后参照前述偶数处理策略。
算法中需要用到判断奇数和偶数的操作(Y%2==0)和除2操作（Y/2）,为提升性能，可考虑使用位运算‘&’（Y&1==0）和‘>>’(Y>>1)。
（二）设计
当Y>X时，若Y为偶数则除2（操作次数加1），若为奇数则先加1再除2（操作次数加2），循环进行直至Y<X,此后再进行X-Y次操作，即可使Y==X。
二 算法实现
```C++ []
class Solution {
public:
    int brokenCalc(int X, int Y) {
        int ans = 0;
        int t = Y;
        while (t > X){
            if ((t & 1) == 0){
                ans += 1;
                t = t >> 1 ;               
            }
            else{
                ans += 2;
                t += 1;
                t = t >> 1;
            }            
        }
        ans += X - t;
        return ans;
    }
};
```
```python3 []
class Solution:
    def brokenCalc(self, X: int, Y: int) -> int:
        ans = 0
        t = Y
        while t > X:
            if t & 1 == 0:
                ans += 1
                t = t >> 1
            else:
                ans += 2
                t = (t+1) >> 1
        ans += X - t
        return ans
```
```Java []
class Solution {
    public int brokenCalc(int X, int Y) {
        int ans = 0;
        while (Y > X){
            if ((Y&1) == 0){
                ans += 1;
                Y = Y >> 1;
            }else{
                ans += 2;
                Y = (Y+1) >> 1;
            }
        }
        ans += X - Y;
        return ans;
    }
}
```
三 复杂度
因每次循环使Y近似缩小一半，故时间复杂度为O(log(Y))；空间复杂度O(1)。