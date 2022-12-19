### 解题思路
从m ~ n的所有数与的结果，由最开始的数**m**确定，最终结果result <= m
对后续的数中，只需知道是否有能对**m**为1的bit位置0的数存在即可
考虑二进制数，1011，比其大且能对其中的1进行与操作后，置1为0的数为 1100，然后判断1100是否在 m ~ n之间
如果在m~n之间，则进行操作1011 & 1100 = 1000，继续查找下一个能对1000中1产生置0的数，重复以上操作
如果不存在，证明数据值bit位不会再被改变，可返回结果
### 代码

```cpp
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int res = m;
        int len = 0;
        int cur = m;
        // 查找bit位中从右到左第一个为1的位置
        while (cur) {
            if (cur & 1) {
                break;
            }
            ++len;
            cur >>= 1;
        }
        // 防止int类型溢出
        long flag = 1 << len;
        // 寻找第一个能置0的数
        long i = nextNum(res, flag);
        while (i <= n && res > 0) {
            res &= i;
            flag <<= 1;
            i = nextNum(res, flag);
        }
        return res;
    }

    long nextNum(int n, long flag) {
        while (n & flag) {
            flag <<= 1;
            n &= n - 1;
        }
        return n | flag;
    }
};
```