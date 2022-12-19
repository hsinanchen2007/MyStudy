思路：
1、既然取1337的模，那么超过1337的部分基本都可以去掉，不管大数什么的，所以乘完之后都记得取模。即(a*b)%c = ((a%c)*(b%c)%c
2、由于b是数组形式，所以逐位进行计算
3、假设计算2^43 = (2^10)^4 * (2^1)^3. 留意到第一位的底数是2，第二位的底数是2^10. 如果我们从最低位开始遍历，计算当前底数的幂，再乘上上一次的结果。
每遍历完一位后，可以算出比当前高一位的底数。继续进行下一位的遍历。
4、计算幂的时候，可以用快速幂算法加速
```
class Solution {
public:
    int superPow(int a, vector<int>& b) {
        int size = b.size();
        int x = a % 1337;
        int res = 1;
        for (int i=size-1; i>=0; i--) {
            int pow = b[i];
            res = (res * qpow(x, pow))%1337;
            x = qpow(x, 10)%1337;
        }
        return res;
    }
    
    int qpow(int x, int n) {
        int res = 1;
        while (n) {
        if (n & 1) {
            res = (res * x) % 1337;
        }
            x = (x * x)  % 1337;
            n >>= 1;
        }
        return res;
    }
};
```

