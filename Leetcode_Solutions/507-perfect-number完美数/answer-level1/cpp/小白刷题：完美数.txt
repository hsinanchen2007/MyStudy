所有真因子加和比较即可

注意平方数的平方根有可能被加两遍，另外记得去掉自身

还有，想想也知道，“完美数”是非常少的，因此可以直接把所有完美数列出来switch，简单粗暴

不过需要事先把所有完美数跑出来，提交结果是很快但过程要花很长时间，不建议

代码：
```
class Solution {
public:
    bool checkPerfectNumber(int num) {
        if(num > 0) {
            int ans = -num;
            int sq = (int)sqrt(num);
            if(sq * sq == num)
                ans -= sq;
            for(int i = 1 ; i <= sq ; i++) {
                if(num % i == 0)
                    ans = ans + i + num / i;
            }
            return ans == num;
        }
        return false;
    }
};
```
