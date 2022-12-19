# 方法一：利用辅助二维数组
- 思路：
  - 利用辅助二维数组
- 时间复杂度：
  - o(n*m)
- 空间复杂度：
  - o(n*m)
```
class Solution {
    //返回该位置下一状态
    int has_life(vector<vector<int>>& tmp, int i, int j){
        //对周围八个位置（在范围内）进行统计
        int m=tmp.size(), n=tmp[0].size(), cnt=0;
        int x[8]={-1,-1,-1,0,0,1,1,1};
        int y[8]={-1,0,1,-1,1,-1,0,1};
        for(int t=0;t<8;t++){
            int xp=i+x[t], yp=j+y[t];
            if(xp>=0 && xp<m && yp>=0 && yp<n) cnt+=tmp[xp][yp];
        }
        //如果是活细胞
        if(tmp[i][j]){
            if(cnt<2 || cnt>3) return 0;
            else return 1;
        }
        //如果是死细胞
        return cnt==3;
    }
public:
    void gameOfLife(vector<vector<int>>& board) {
        //第一版：用一个辅助二维数组，进行记录
        //创建二维数组，复制
        int m=board.size(), n=board[0].size();
        vector<vector<int>> tmps(m, vector<int>(n, 0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                tmps[i][j]=board[i][j];
            }
        }
        //遍历所有位置，根据状态和规则进行下一状态的计算
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                board[i][j]=has_life(tmps, i, j);
            }
        }
    }
};
```

# 方法二：原地计算
- 思路：
  - 利用高位存储下一状态的信息，遍历后还原
- 时间复杂度：
  - o(n*m)
- 空间复杂度：
  - o(1)
- 结果:
  - 用时：66%（4ms）
  - 内存：100%
```
class Solution {
    //返回该位置下一状态
    int has_life(vector<vector<int>>& tmp, int i, int j){
        //对周围八个位置（在范围内）进行统计
        int m=tmp.size(), n=tmp[0].size(), cnt=0;
        int x[8]={-1,-1,-1,0,0,1,1,1};
        int y[8]={-1,0,1,-1,1,-1,0,1};
        for(int t=0;t<8;t++){
            int xp=i+x[t], yp=j+y[t];
            if(xp>=0 && xp<m && yp>=0 && yp<n) cnt+=tmp[xp][yp] & 1; //低位信息储存的是原状态，统计低位
        }
        //如果是活细胞
        if(tmp[i][j]){
            if(cnt<2 || cnt>3) return 0;
            else return 1;
        }
        //如果是死细胞
        return cnt==3;
    }
public:
    void gameOfLife(vector<vector<int>>& board) {
        //第二版：用原数组的高位进行记录
        //遍历所有位置，根据状态和规则进行下一状态的计算
        int m=board.size(), n=board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                board[i][j]+=has_life(board, i, j)<<1; //将下一状态存储到高位
            }
        }
        //还原数组信息为高位，即下一状态
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                board[i][j]>>=1;
            }
        }
    }
};
```
> -------------------------------------------------
> > \>\>\>[**我的算法题本 - 算法菜鸟之路**](https://github.com/lorwin0130/Algorithm-newbie)
> 会记录做过题的**不同解法、思路、套路总结以及个人思考**
> 欢迎各位大佬**来讨论呀**，欢迎**star (U^_^U)** 
> -------------------------------------------------