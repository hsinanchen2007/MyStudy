观察二进制位数分别是1，2，3的情况，即0-1,2-3,4-7，可以发现二进制是
0 1
10 11
100 101 110 111
...
每多一位二进制位，可以看作往下一层，其二进制是在该层之上的所有数最前加上一个1。那么在计算这一层时，通过维护上一层的数字个数，就可以利用之前的计算结果直接加一得到。代码如下:
```
class Solution {
public:
    vector<int> countBits(int num) {
        int bitNum = 1;
        vector<int> dp(num + 1);
        int tmp = bitNum;
        for(int i = 1;i<=num; ++i){
            dp[i] = dp[i - bitNum] + 1;
            --tmp;
            if(tmp == 0){
                bitNum = i + 1;
                tmp = bitNum;
            }
        }
        return dp;
    }
};
```
