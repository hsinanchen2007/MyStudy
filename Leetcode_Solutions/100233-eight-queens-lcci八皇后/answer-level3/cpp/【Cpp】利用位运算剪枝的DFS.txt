### 解题思路

以4皇后，8位整型为例讲解里面的位运算。一开始初始化: row, cols, pie,na都是 00000000

下面语句的目的是获取可以放皇后的位置(二进制表示的1)

```c
int bits = ( ( ~(col | pie | na) )  & ( (1 << n) - 1 ));
```

`~(cols | pie | na)` 按位或，然后按位取反，也就是先得到所有1占据的位置，接着把1变为0，把0变成1，这里结果就是11111111.

`((1 << n) — 1)` 首先将00000001左移n位(n=4), 得到 00010000, 然后-1得到00001111,

将两者按位与，就得到00001111。1就是可以放皇后的位置。

**注意**，如果没有`& ((1 << n) — 1)`操作，就无法清空高位部分的1。

下面语句的目的是获取最低位的1，也就是0000111(1)

```c
int pos = bits & -bits; // 取到最低位的1
```

bits是00001111, -bits是10001111, 但是在运算过程中, -bits会以补码形式出现，也就是11110001, 因此实际是00001111 & 11110001 = 00000001

下面的语句是在bits中p的位置上放上皇后， 00001111 - 00000001 = 00001110

```c
bits = bits - pos; //表示在p位置上放入皇后
// 或
bits = bits & (bits — 1) // 也就是把最后一位变为0
```

递归一层，在原来的位置上加上p, 对于左下角要左移，右下角要右移(不需要再考虑数组的边界了)

```c
DFS(n, row + 1, cols | p, (pie | p) << 1, (na | p) >> 1) 
```

于是新的row, cols, pie, na是 00000001, 00000001, 00000010, 00000000. (是原来棋盘的镜像翻转)

接着计算bits, 就是 00001100, 只剩下两个位置可以放皇后了。



```cpp
class Solution {
vector<vector<string>> ans;
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<int> comb(n, 0);
        DFS(n, 0, 0, 0, 0, comb);
        return ans;
    }
    void DFS(int n, int row, int col, int pie, int na, vector<int>& comb){
        if ( row == n){
            vector<string> res = generateResult(comb);
            ans.push_back(res);
            return ;
        }
        int bits = ( ( ~(col | pie | na) )  & ( (1 << n) - 1 ));
        while (bits){
            int pos = bits & -bits;
            comb[row] = getPos(pos);
            bits -= pos;
            DFS(n, row+1, col|pos, (pie|pos) <<1 , (na|pos) >> 1, comb);
        }
        return ;
    }

    int getPos(int i){
        int count = 0;
        while (i){
            count++;
            i >>= 1;
        }
        return count -1;

    }

    vector<string> generateResult(vector<int>& comb){
        vector<string> res;
        for (int i = 0; i < comb.size(); i++){
            string s(comb.size(), '.');
            s[comb[i]] = 'Q';
            res.push_back(s);
        }
        return res;

    }

};
```