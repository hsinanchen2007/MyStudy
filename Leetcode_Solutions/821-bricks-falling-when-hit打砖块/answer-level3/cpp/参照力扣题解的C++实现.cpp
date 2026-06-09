UnionFindSet类封装多种方法：
1. 构造函数UnionFindSet(R,C)
2. 找到祖先函数find(x),对经过的节点进行路径压缩
3. 合并函数unionSet(),利用rank保持树尽量平衡
4. 得到当前未掉落的砖块数量函数getTopBricks()
5. 对敲打完所有砖块的结果建立并查集的函数buildUFS()
6. 加砖块函数addBricks(A,grid,ans,r,c),同时添加结果
然后在solution中直接走时光倒流+并查集+加砖块流程。
```
class UnionFindSet{
    private:
        vector<int> par;
        vector<int> rank;
        vector<int> numOfBricks;
        int Rows;
        int Cols;
    public:
        UnionFindSet(int R,int C):par(R*C+1,0),rank(R*C+1,0),numOfBricks(R*C+1,1),Rows(R),Cols(C)
        {
            for(int i = 0;i<R*C+1;i++)
                par[i] = i;
        }
        int find(int x)
        {
            if(par[x] != x)
                par[x] = find(par[x]);
            return par[x];
        }
        void unionSet(int x,int y)
        {
            int xp = find(x);
            int yp = find(y);
            if(xp == yp)
                return;
            if(rank[xp] < rank[yp])
                swap(xp,yp);
            if(rank[xp] == rank[yp])
                ++rank[xp];
            par[yp] = xp;
            numOfBricks[xp] += numOfBricks[yp];
        }  
        int getTopBricks()
        {
            return numOfBricks[find(Rows*Cols)] - 1;
        }
        int getRoom() //返回R*C
        {
            return Rows*Cols - 1;
        }
        int index(int r,int c)
        {
            return r * Cols + c;
        }
        void buildUFS(vector<vector<int>>& A)
        {
            for(int r = 0;r < Rows;r++)
            {
                for(int c = 0;c < Cols;c++)
                {
                    if(A[r][c])
                    {
                        int i = index(r,c);
                        //与天花板连接
                        if(r == 0)
                            unionSet(i,Rows*Cols);
                        //与上方方块连接
                        if(r && A[r-1][c])
                            unionSet(i,index(r-1,c));
                        //与左边方块连接
                        if(c && A[r][c-1])
                            unionSet(i,index(r,c-1));
                    }
                }
            }
        }
        void addBricks(vector<vector<int>>& A,vector<vector<int>>& grid,vector<int>& ans,int r,int c)
        {
            int topBricks = getTopBricks();
            if(grid[r][c] == 0)
                ans.push_back(0);
            else
            {
                int i = index(r,c);
                //把i和四个方向的砖块连接
                vector<int> dr{1,0,-1,0};
                vector<int> dc{0,1,0,-1};
                for(int k = 0;k < 4;k++)
                {
                    if(r+dr[k]>=0 && r+dr[k]<Rows && c+dc[k]>=0 && c+dc[k]<Cols && A[r+dr[k]][c+dc[k]])
                        unionSet(i,index(r+dr[k],c+dc[k]));
                }
                //把i和天花板的砖块连接
                if(r == 0)
                    unionSet(i,Rows*Cols);
                A[r][c] = 1;
                ans.push_back(max(0,getTopBricks()-topBricks-1));
            }
            return;
        }
};
class Solution {
public:
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        int R = grid.size();
        int C = grid[0].size();
        //A是grid去掉所有hit的砖块的结果(因此掉落的其余砖块仍然保留)。
        vector<vector<int>> A = grid;
        for(auto hit:hits)
            A[hit[0]][hit[1]] = 0;
        //根据A建立并查集
        UnionFindSet ufs(R,C);
        ufs.buildUFS(A);
        //时光倒流，倒着添加砖块更新结果
        vector<int> ans;
        for(int i = hits.size()-1;i >= 0;i--)
            ufs.addBricks(A,grid,ans,hits[i][0],hits[i][1]);
        //逆序输出
        vector<int> reversed_ans;
        for(int i = ans.size()-1;i >= 0;i--)
            reversed_ans.push_back(ans[i]);
        return reversed_ans;
    }
};
```
