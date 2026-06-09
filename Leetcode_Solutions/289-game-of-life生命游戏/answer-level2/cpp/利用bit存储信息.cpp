### 解题思路
不使用额外空间修改的话，一般想到的就是利用bit存储信息。在本题中使用低两位，最低位表示上一个状态，第二位表示最新的状态，在更新数组的时候只用到最低位的状态，数组更新完毕之后只要将最低位的信息抹去即可。表示的时候0表示dead，1表示live。因此具体表示为：
`00 -> 上一个状态为dead下一个状态也为dead`

`01 -> 上一个状态为live下一个状态为dead`

`10 -> 上一个状态为dead下一个状态为live`

`11 -> 上一个状态为live下一个状态也为live`
**因为初始细胞的状态为0或1，我们可以看做是00 和 01，这个状态表示细胞的下一状态为dead**
当得到周围细胞存活情况的时候根据题意得知总共有四种情况：
1. 如果活细胞周围八个位置的活细胞数少于两个，则该位置活细胞死亡；
    此时细胞的状态变化为 00 -> 00， 01 -> 01，因此这个条件我们可以不用管，因为初始条件就是这样的
2. 如果活细胞周围八个位置有两个或三个活细胞，则该位置活细胞仍然存活
    此时细胞的状态变化为 00 -> 00， 01 -> 11
3. 如果活细胞周围八个位置有超过三个活细胞，则该位置活细胞死亡；
    此时细胞的状态变化为 00 -> 00 01 -> 01 这个状态也与初始状态一致，也不用管
4. 如果死细胞周围正好有三个活细胞，则该位置死细胞复活；
    此时细胞的变化状态为 00 -> 10 01 -> 11

因为条件2包含了条件4，为了简化操作，最终划分为4个不重不漏区间
-  [0，2)：同上面条件1，不进行任何操作
- [2,2]: 更新操作为 00 -> 00 01 -> 11，使用位运算
- [3,3]: 更新操作为：00 -> 10 01 -> 11 ，如果低位为1则更新为3如果低位为0更新为2
- (3,8]:同上条件3，不进行任何操作



[思路来源](https://leetcode.com/problems/game-of-life/discuss/73223/Easiest-JAVA-solution-with-explanation)
### 代码

```cpp
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        if(board.empty())
            return;
        int _row = board.size();
        int _col = board[0].size();
        for(int i = 0; i < _row; i++)
            for(int j = 0; j < _col; j++){
                // 找出8个位置中上一个状态为1的个数
                int count = get_live(board,i,j,_row,_col); 
                // 根据条件适当简化判断条件，保证不重不漏

                // if(count < 2){
                //     // 00-> 00 01 -> 01; 不用管 
                // }
                if(count == 2){
                    // 00 -> 00 01 -> 11
                    board[i][j] = board[i][j] + (board[i][j] << 1);
                }
                if(count == 3){
                    // 00 -> 10 01 -> 11 
                    board[i][j] = board[i][j] & 1 ? 3 : 2;
                }
                // if(count > 3){
                //     // 00 -> 00 01 -> 01 不用管
                // }
                
            }
        
        // 抹去上一个状态，只要将最低位抹去即可
        for(int i = 0; i < _row; i++)
            for(int j = 0; j < _col; j++)
                board[i][j] = board[i][j] >> 1;
    }

    int get_live(vector<vector<int>>& board, int i, int j, int _row, int _col){
        int count = 0;
        for(int k = max(i-1,0); k < min(i+2,_row); k++)
            for(int l = max(j-1,0); l < min(j+2,_col); l++)
                count += board[k][l] & 1;
        count -= board[i][j]&1;
        return count;
    }
};
```