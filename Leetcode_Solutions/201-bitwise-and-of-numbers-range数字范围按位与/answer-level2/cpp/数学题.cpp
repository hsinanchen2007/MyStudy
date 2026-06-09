对于区间[m,n]，如果其中存在某个数k能整除2，则该数k的最后一位必为0，进而最终的结果其最后一位也为0；
对整个区间进行右移1位，即[m>>1, n>>1]，若其中存在某个数k1能整除2，则最终的结果其倒数第二位为0；
以此类推。
关键：如何判断任意区间[m,n]中是否存在某个数k能整除2.若区间内包含2个及以上整数，必然存在整除2的数；否则，m==n,如果m能整除2，则区间存在整除2的数。
代码如下：
```
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int res=0;
        for(int b=0; m; m>>=1, n>>=1, ++b){
            if(m<n || (m&1)==0) continue;
            res|=1<<b;
        }
        return res;
    }
};
```

进一步思考：对于区间[m,n]中，若存在连续的数k1,k2，则k1&k2最后一位必然为0.整体右移一位，以此类推。最终，其求得的是区间[m,n]所有数的公共前缀。
代码：
```
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        for(; n>m; n&=n-1);
        return n;
    }
};
```


