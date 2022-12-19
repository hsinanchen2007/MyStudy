### 进阶:状态压缩+位运算
先上代码
#### code
```cpp
#include <iostream>
using namespace std;
class Solution
{
public:
    int ans = 0;
    int full;
    void dfs(int col, int leftdown, int rightdown)
    {
        if (col == full) //每一列都已经有皇后了，说明满了
        {
            ++ans;
            return;
        }
        // col|leftdown|rightdown 任何一个是1都不行，表示在皇后攻击范围内
        // 取反后，1是可以放的位置，0是不能放的
        // 与 11111(n个1)与运算后把高位舍去，剩下的位数为棋盘的边长
        int now = full & ~(col | leftdown | rightdown);
        while (now)
        {
            // 取最低一位1，表示在这里放一个皇后
            int lowbit = now & -now;
            now -= lowbit;
            // 更新3个状态
            // row是没有用的，因为row已经包含在col里面了
            // col=col+lowbit
            // leftdown=(leftdown+lowbit)<<1
            // rightdown=(rightdown+lowbit)>>1
            dfs(col + lowbit, (leftdown + lowbit) << 1, (rightdown + lowbit) >> 1);
        }
    }
    int totalNQueens(int n)
    {
        full = (1 << n) - 1;
        dfs(0, 0, 0);
        return ans;
    }
};
```
一种非常牛逼的解法，需要有高超的位运算能力。

简单来说，就是把原来的4个bool数组压缩成了3个int数，用这三个数的每一位表示约束条件。  
因为不需要输入方案，只求方案个数，所以不需要存储之前的皇后位置。

#### 状态表示
`1`表示在皇后的攻击范围里面  
`0`表示可以放皇后

#### full
```
n=5
full=2^5-1=31=11111
```
5个1表示放满了

#### lowbit
取二进制数的最低位  
在while里面起到遍历当前行所有能放皇后的位置
```
lowbit(x)=x&-x
```

#### col
这个最容易理解，如果某一位上是1，就说明之前在这列上有皇后。  
位数对应列数

假设现在dfs到第三行，前面两行的皇后分别放在第一和第四列
```
1 0 0 0
0 0 0 1
1 0 0 1

col=1001
```

#### leftdown
右上到左下的对角线,加上当前行的皇后位置后，**整体**左移一位

dfs到第三行
```
  0 0 1 0
  1 0 0 0
1 1 0 0 0

leftdown=11000
实际上最高位的1被舍去了，因为有full&
```

#### rightdown
左上到右下的对角线，加上当前行的皇后位置后，**整体**右移一位
```
0 1 0 0
0 0 0 1
0 0 0 1 1

rightdown=00011
实际上最右侧的1被舍去了，位运算的overflow
```