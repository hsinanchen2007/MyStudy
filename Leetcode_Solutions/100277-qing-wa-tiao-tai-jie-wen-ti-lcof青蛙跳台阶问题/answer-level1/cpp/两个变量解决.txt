![微信图片_20200309180524.png](https://pic.leetcode-cn.com/5aa32aa08c9415b44c99f5e0f681ab465d14f96930bb5b1560e7eaefc7f3f249-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20200309180524.png)

思路：
- 这更多是一个数学问题，多列几项就知道里面的规律其实是斐波那契数列，是一个变种
- 所以我们只需要关注两项就好了
- 和面试题10- I一样，前两项变成了第一项和第二项，而不是第0项和第1项，可以用除以2的余数为0或者1来改变odd和eve
```
class Solution {
public:
    int numWays(int n) {
        if(n == 0){
            return 1;
        }
        int odd = 1;
        int eve = 2;
        if(n > 2){
            for(int i = 3; i <= n; i++){
                if(i % 2 == 0){
                    int count = (eve + odd) / 1000000008;
                    eve = count + (eve + odd) % 1000000008;
                }
                else{
                    int count = (eve + odd) / 1000000008;
                    odd = count + (eve + odd) % 1000000008;
                }
            }
        }
        return n % 2 == 0 ? eve : odd;
    }
};
```
