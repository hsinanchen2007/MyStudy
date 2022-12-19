### 解题思路
1. 设结果为`res`, 考虑结果的第$i$位, 如果第$i$位为1, 那么$[m, n]$之间所有的数的第$i$位均为1
2. 判断$m$的第$i$位是否为1, 如果为1, 判断$[m, n]$是否包含在区间`m & ~(1<<i)-1`至`m & ~((1<<i)-1)+(1<<i)`(左闭右开)之间
3. 如果在说明结果的第$i$位为1, `res+=1<<i`
### 代码

```c++ []
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int res = 0;
        for(int i=0; (1ll << i)<=m; ++i){
            if(m >> i & 1){
                if((m & ~((1<<i)-1ll))+(1<<i) > n)
                    res +=1<<i;
            }
        }
        return res;
    }
};
```