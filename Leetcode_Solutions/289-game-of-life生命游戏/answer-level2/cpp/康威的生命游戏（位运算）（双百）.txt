## 解题思路

This implementation supports in-place update of each cell by adopting a slightly different key for each state:
- 0 (00) for dead cells which remains dead in the next round
- 1 (01) for living cells that will die in the next round
- 2 (10) for dead cells that will be revived in the next round
- 3 (11) for living cells that remains alive in the next round

By looking at the binary representation of the keys, it is clear that the first (rightermost) digit represents the current state, whereas the second digits represents the next state. In fact, by extension, a 32-bit integer can store up to 32 different states, and each states can be easily accessed and modified through bit operations.

Alternatively, we can imagine that we managed to store the current state in the remainder, and the updated state in the quotient, when the key is divided by two. The bitwise "and" (&) as used in:

```
if (board[x][y] & 1 == 1)
```
is essentially equivalent to:
 
```
if (board[x][y] % 2 == 1) 
```
and the rightshift (>>) as used in:

```
board[i][j] >>= 1
```
is equivalent to:

```
board[i][j] /= 2
```
Bit operations are arguably a bit faster, though the difference may not be very pronounced as most modern compilers compiles modulo and powers of two operations as bit operations.

Ps. Since three nested loops are used, I defined a `loop` macro to save code.

----------------------------------------------------------------我是中文分割线-----------------------------------------------------------------
![Screenshot 2020-04-02 at 11.04.01 PM.png](https://pic.leetcode-cn.com/22c8e1fb3ed25187571de380ab4b01da178f9d7a2ada937f08affbb1661756d2-Screenshot%202020-04-02%20at%2011.04.01%20PM.png)

## 解题思路
这道题要求我们根据每个格子周围 8 个格子的现有状态判定格子未来状态，最后输出每个格子的未来状态，因此总共有 4 种可能状态，而且数组每项同时得储存 2 个状态（现在，未来）。倘若数组每项只储存 0 或 1 的话，数组每项最多只能同时储存一个状态，因此数组每项得用更大的数来标明更多种状态。鉴于现在、将来各有两种可能状态，我们总共需要四种状态。于是我们定义各状态如下
- 0（00）： 有些格子死了，它仍将死去。
- 1（01）： 有些格子活着，它已经死了。
- 2（10）： 有些格子死了，它还活着。
- 3（11）： 有些格子活着，它依然活着。

我们发现很（并不）凑巧的是，每个值除以二的余数刚好对应他现在的状态，而他除以二的商刚好对应他将来的状态。实际上，这是因为我们储存当前状态用的是编码二进制的第一位，而储存将来状态用的是编码二进制的第二位，因此，我们取二余数的时候，就访问了编码第一位，而取二商的时候，相当于将编码右移了一位，访问了原编码的第二位。因此：
```
if (board[x][y] & 1 == 1)
```
和
```
if (board[x][y] % 2 == 1) 
```
以及
```
board[i][j] >>= 1
```
和
```
board[i][j] /= 2
```
实际上是两两等价的。

如果直接使用位运算来访问和修改每一位的值，理论上可以提高计算效率（实际上现代编译器通常会把模2，乘除2的运算编译成位运算，所以实际没啥差别）。当然如果理解了这种编码二进制表达每一位的含义，那么用位运算实际上比用模、乘除更直观。同时，一个`int`有 32 位，一个`long long`更是有 64 位，我们实际上完全可以用一项储存更多信息，而使用位运算可以让我们方便的实现这一点。

另外我们注意到，题目中的条件实际上也可以这样描述：
1. 如果周围少于两个活格子，那么无论如何下一轮都是死；
2. 如果周围有两个活格子，那么当天格子状态延续；
3. 如果周围有三个活格子，那么当天状态变更；
4. 如果周围大于三个活格子，那么下一轮无论如果都是死。

鉴于死的格子表述是 0，第 1、4 种情形实际上状态编码没有变化，因此我们只需要判断一个格子是否满足 2、3即可。

![Gospers_glider_gun.gif](https://pic.leetcode-cn.com/9c9403fd4fd879943dc481a443a452cb2e95f03477c5aece561ef0fe8b370da6-Gospers_glider_gun.gif)
图为非常酷炫的“滑翔机大炮”。（https://en.wikipedia.org/wiki/Gun_(cellular_automaton)）

另外，由于这个题目里用到了 3 个（原先的解法用到了 4 个）循环，为了减少代码量（为了代码好看），定义了一个`loop`的宏，希望不影响大家理解。

-----------------------------------------------------------------我是分割线------------------------------------------------------------------
### 代码/Code

```cpp
// Iterate from 0 to n - 1
#define loop(i, n) for (int i = 0; i < int(n); i++)
int dx[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dy[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board)
    {
        int count, cur, h = board.size(), w = board[0].size(), x, y;
        loop(i, h) loop(j, w)
        {
            count = 0;
            loop(k, 8)
            {
                x = i + dx[k];
                y = j + dy[k];
                if (x < 0 || y < 0 || x >= h || y >= w)
                    continue;
                if (board[x][y] & 1 == 1)
                    count++;
            }
            // If the current cell is alive, and there are two live neighbours, 
            // it remains alive;
            if (count == 2 && (board[i][j] & 1) == 1)
                board[i][j] += 2;
            // If the current cell has three live neighbours,
            // it will be alive in the next round regardless of its current state
            else if (count == 3)
                board[i][j] += 2;
        }
        // Update the state of each cell
        loop(i, h) loop(j, w) board[i][j] >>= 1;
    }
};
```