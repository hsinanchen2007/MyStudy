### 解题思路
首先将两个数进行异或运算，并对得到的值与0x00000001(32的数据)按位与，得到最后一位。如果最后一位为1，则计数变量count加一，之后将异或得到的数n右移一位，即实现对n的每一位的检测。

### 代码

```c
int hammingDistance(int x, int y){
    int n = 0, temp = 0;
    int count = 0;
    n = x ^ y;
    while(n)
    {
        if(temp = n & 0x00000001)
            count += 1;
        n >>= 1;
    }
    return count;
}
```