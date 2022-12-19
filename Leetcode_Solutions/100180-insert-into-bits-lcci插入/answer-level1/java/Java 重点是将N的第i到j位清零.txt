整体思路是将N的第i到j位清零得到新的N，然后将M左移i位后与新N进行按位或运算。
要将N的第i到j位清零，需要构造一个第i到j位为0，其他位为1的二进制数K与N进行按位与运算。我们可以先构造一个第i到j位为1，其他位为0的二进制数L，再将其取反即可获得K。L可以由前（j-i+1）位为1，其余位为0的二进制数H左移i位获得。
```
H = (1 << j - i + 1) - 1;
L = H << i;
K = ~L;
```
具体代码：
```
class Solution {
    public int insertBits(int N, int M, int i, int j) {
        N &= ~((1 << j - i + 1) - 1 << i);
        return N | M << i;
    }
}
```
