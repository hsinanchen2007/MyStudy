执行用时 :8 ms, 在所有 cpp 提交中击败了38.98%的用户

内存消耗 :8.3 MB, 在所有 cpp 提交中击败了76.75%的用户

突发奇想用递归做，
首先将符号用flag存，flag为0表示正数，为1表示负数。
终止条件：
x == 0
操作：
因为x ！=0，说明还需往结果尾部加入数据，所以将结果值乘10，再加上x%10，x更新为x/10（将最后一位已放入结果值的数据拿走），然后继续递归。

注意，结果值用了long，这样就不用担心溢出了。用float会出错（输入为-2147483412）。
```
class Solution {
public:
    int reverse(int x) {
        long res = 0;
        if (x == INT_MIN)
            return res;
        int flag = 0;
        if (x < 0)
        {
            flag = 1;
            x = -x;
        }
        recursion(x, res);
        if (res > INT_MAX)
            res = 0;
        return int(res) * pow(-1, flag);
    }
    void recursion(int x, long& res)
    {
        if (x == 0)
            return ;
        res = res * 10;
        res += x % 10;
        x = x / 10;
        recursion(x, res);
        return ;
    }
};
```
