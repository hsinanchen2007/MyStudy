求解思路：
1 由于求阶乘中包含10的数量，10=2*5，而瓶颈在于5的数量，顾求5的数量；
2 同时对于大于5^x的数，需要进行计数补偿: cnt = N/5 + N/25 + N/125.... N/5^n;

```
class Solution {
public:
    int trailingZeroes(int n) {
        //由于求阶乘中包含10的数量，10=2*5，而瓶颈在于5的数量，顾求5的数量；
        //同时对于大于5^x的数，需要进行计数补偿: cnt = N/5 + N/25 + N/125.... N/5^n;
        int cnt(n/5);
        while(n/=5) cnt += n/5;
        return cnt;
    }
};
```
![image.png](https://pic.leetcode-cn.com/af3faf161d09d3468829106ef5cca42ff4af49c17f5cf255ad4d142c6307ed05-image.png)
