折腾折腾，发现最近做的几道dfs题目似乎是同一个思想：把一堆东西塞到某一个新的地方
所以需要考虑的是塞还是不塞，如果塞塞哪一个，要塞到哪一个位置里面去

这道题按照这个思路就是有n个棋子，想要塞到一个n*n的棋盘里面去
要怎么遍历这个棋盘呢？一个格子一个格子遍历？ 一行一行遍历？ 一列一列遍历？
如果按照一个格子一个格子遍历：
那么来到一个格子，我是放棋子进去还是不放进去
```
class Solution {
    vector<vector<string>> res;
    int n;
    void dfs(vector<bool>& col, vector<bool>& dig, vector<bool>& udig, vector<string>& v, int rownum)
    {
        if(rownum == n)
        {
            res.push_back(v);
            return;
        }
        for(int j = 0; j < n; j++)
        {
            if(col[j] || dig[j - rownum + n] || udig[j + rownum])
                continue;
            v[rownum][j] = 'Q';
            col[j] = dig[j - rownum + n] = udig[j + rownum] = true;
            dfs(col, dig, udig, v, rownum + 1);
            col[j] = dig[j - rownum + n] = udig[j + rownum] = false;
            v[rownum][j] = '.';
        }
    }


public:
    vector<vector<string>> solveNQueens(int _n) {
        n = _n;
        //这里2*n的原因：想一下棋盘是关于对角线对称的，一侧是有n个，另外一侧也是n个，去掉中间的重复算就是2n - 1
        //row是记录行被用过没有，col是记录列被用过没有，dig是记录y = x对角线被用过没有，udig是记录y = -x对角线被用过没有
        int N = 2*n;
        vector<bool> row(n, false);
        vector<bool> col(n,false), dig(N, false), udig(N, false);
        //还有一点是关于行列以及对角线的对应关系
        //x,y对应的y = x + b对角线是n + (y - x), y = -x + b对角线是 y + x
        vector<string> v(n, string(n, '.'));
        dfs(col, dig, udig, v, 0);
        return res;
    }
};
```


如果按照行遍历：
这一行我是放哪一个格子里面去？
```
class Solution {
    vector<vector<string>> res;
    int n;
    void dfs(vector<bool>& row,vector<bool>& col,vector<bool>& dig,vector<bool>& udig,vector<string>& v,int rowidx,int colidx,int cnt)
    {
        if(cnt == n)
        {
            res.push_back(v);
            return;
        }
        if(colidx == n)
        {
            rowidx++;
            colidx = 0;
        }
        if(rowidx == n)
            return;
        dfs(row, col, dig, udig, v, rowidx, colidx+1, cnt);
        if(!row[rowidx] && !col[colidx] && !dig[n + colidx - rowidx] && !udig[colidx + rowidx])
        {
            v[rowidx][colidx] = 'Q';
            row[rowidx] = col[colidx] = dig[n + colidx - rowidx] = udig[colidx + rowidx] = true;
            dfs(row, col, dig, udig, v, rowidx, colidx + 1, cnt + 1);
            row[rowidx] = col[colidx] = dig[n + colidx - rowidx] = udig[colidx + rowidx] = false;
            v[rowidx][colidx] = '.';          
        }          
    }
public:
    vector<vector<string>> solveNQueens(int _n) {
        n = _n;
        
        vector<string> v = vector(n, string(n, '.'));
        vector<bool> row(n, false), col(n, false), dig(2*n, false), udig(2*n, false);
        dfs(row, col, dig, udig, v, 0, 0, 0);
        return res;
    }
};
```
还写了一些别的leetcode的题解，分享一下看看有没有需要的，题解还会更新：[https://www.yuque.com/books/share/300e07be-6fc9-417d-bb05-c50f5dea1618?#](https://www.yuque.com/books/share/300e07be-6fc9-417d-bb05-c50f5dea1618?#)
顺带给自己推一波公众号，要是有兴趣可以关注：**麦芽糖的笔记本**
![image.png](https://pic.leetcode-cn.com/95c54eba219d34f176350f6968ff8d934a93879a43a12f926b2e05148b5833ca-image.png)

公众号回复**LC**，可以下载题解的pdf版本，pdf也会更新

![image.png](https://pic.leetcode-cn.com/a533ef6e9a37396c93e0d965e5ef389996a90e8c5b6a05d35aa19d918dcf8b86-image.png)
