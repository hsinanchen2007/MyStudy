### 解题思路
(1)使用“.”初始化n的矩阵string
(2)从第l列的第i，l和i的取值范围都是0~n-1
(3)设置queen[l][i]为Q，后面别忘了恢复回来queen[l][i]为“.”
(4)使用一个pair数组记录前面Q的坐标
(5)一致往下DFS，当最终l遍历到最后列的时候，其实这时候可以保存整个路径
(6)过程中，没DFS一个li就要去pair中找是否 l i位置可以放
(7)判断l i是否可以放的方法其实很简单，就是遍历pair，看l是否在pair中能找到行，这里列不用考虑，能找到就返回这个位置不能放Q，
如果横坐标找不到就找左对角线，及右对角线，其实可以看出l i直接转化下就能与对角线产生关系，所以很好算

### 代码

```cpp
class Solution {
public:
    int getrx(int x, int y, int n){
        if (x == y) {
            return n ;
        }

        if (x < y) {
            return n - (y - x);
        } 

        return n + (x - y);
    }

    int getlx(int x, int y, int n){
        return x + y + 1;
    }
    bool findiscanput(vector<pair<int, int>> &dp, int y, int x, int n) {
        
        for (auto it:dp) {
            if (it.second == x) { //如果当前要放的Q横坐标位置再dp中有直接返回，因为y左边天然不会一样，所以不用比较
                return false;
            }

            if (getrx(it.second, it.first, n) == getrx(x, y, n)) {               //判断是否在左斜线上，其实斜线也可以看做n条，只要算出Q皇后在斜线树就好
                return false;
            }

            if (getlx(it.second, it.first, n) == getlx(x, y, n)) {               //判断是否在右斜线上
                return false;
            }
        }

        return true;
    }
    void bfs(int l, int &n, vector<string> &Queen, vector<vector<string>> &retv, vector<pair<int, int>> &dp) {
        if (l == n - 1) { //能走到最后的说明能做为解决方案的情况
            //printf("%d \r\n", n);
            retv.push_back(Queen);
            return;
        }

        for (int i = 0; i < n;  i ++) {
            if (findiscanput(dp, l + 1, i, n)) { //如果第l层第i个位置可以放
                Queen[i][l + 1] = 'Q';
                dp.push_back(make_pair( l + 1, i));
                bfs(l + 1, n, Queen, retv, dp); //第l层，第i个位置
                //根据第l层第i个位置，去除掉上下斜线的内容
                dp.pop_back();
                Queen[i][l + 1] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ret;
        if ( n == 0) {
            ret.push_back(vector<string>());
            return ret;
        }
        string tmp;

        for (int i = 0; i < n;  i ++) {
            tmp += ".";   
        }
        vector<string> Queen(n, tmp);
        vector<pair<int, int>> dp;

        for (int i = 0; i < n;  i ++) {  
            Queen[i][0] = 'Q';
            dp.push_back(make_pair(0,i));
            bfs(0, n, Queen, ret, dp); //第l层，第i个位置
            dp.pop_back();
            //根据第l层第i个位置，去除掉上下斜线的内容
            Queen[i][0] = '.';
        }
        return ret;
    } 
};
```