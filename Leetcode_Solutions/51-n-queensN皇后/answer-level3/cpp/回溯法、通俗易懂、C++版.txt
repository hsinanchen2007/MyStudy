首先，满足解题条件的是同一 行/列/斜线/反斜线 上只能存在一个皇后；

I、假设：

    1）矩阵dp[n][n]表示棋盘；
    2）dp[row][col]表示第 row+1 行第 col+1 列的格子；

II、可以得到规律：

    0）解释一下，这里主对角线和副对角线跟线性代数里面相反（不知道为什么官网要这么做QAQ）；
    1）同一主对角线的row+col是相等的，因此可以用这个特性表示某一主对角线是否有皇后；
    2）同一副对角线的row-col是相等的，同上；
    根据满足题目的条件可以推出下面的结论。

III、于是我们可以设三个数组用于表示当前格子（dp[row][col]）所在的列、主对角线、副对角线是否有皇后：

    1）列：diagon_col；
    2）主对角线：diagonal_right;
    3）副对角线：diagonal_left;
    三个数组都初始化为true，表示所有的列、主对角线、副对角线都可以放置皇后；

IV、再设置临时结果集和最终答案矩阵：

    1）temp，初始化为n*n的矩阵，该矩阵都为 . ；
    2）ans；初始化为空；

V、解答过程

    1）从0行（row=0）开始进行放置皇后；如果已经到了最后一行（row==n），则保存结果并退出；
    2）每次放置皇后从第0列（col=0）开始循环：
    如果当前格dp[row][col]所在的列、主对角线、从对角线都没有皇后（即diagonal_col[col]==true，diagonal_right[row+col]==true，diagonal_left[row-col+n-1]==true），则在当前位置放置皇后，更新对应数组为false；
    然后在下一行（row+1）放置皇后；
    如果前面的步骤发现有不满足条件的（即按照之前的放置位置不能满足解题条件），则移除已经放置的皇后，在下一个可行的位置继续放置，直到跳出循环。

```
class Solution {
public:
    int nn=0;
    vector<bool>* diagonal_col=NULL;//列
    vector<bool>* diagonal_right=NULL;//主对角线
    vector<bool>* diagonal_left=NULL;//从对角线
    vector<string>* temp=NULL;//临时结果集
    vector<vector<string>>* ans=NULL;//答案集
    
    void solve(int row){
        if(row == nn){
            (*ans).push_back(*temp);//已经到第n行，找到解决方案，放入结果集，返回
            return;
        }
         for(int col=0;col<nn;col++){//每次从第一列开始，依次往后扫描
            int right = col + row;//同一条主对角线的行列和是一个常数，用来标记条该主对角线是否可以放置皇后
            int left = row - col + nn-1;//从对角线，因为从对角线的row-col最小值是0-(n-1)为负数，所以要加上n-1
            if((*diagonal_col)[col]&&(*diagonal_right)[right]&&(*diagonal_left)[left]){
                (*temp)[row][col] = 'Q';//当前格子（当前行的col列）放置皇后
                (*diagonal_col)[col] = false;//本列已经有皇后，更新为false，表示本列不能再放置皇后了
                (*diagonal_right)[right] = false;//当前格子所在的主对角线已经有皇后，更新为false
                (*diagonal_left)[left] = false;//当前格子所在的从对角线已经有皇后，更新为false
                
                solve(row+1);//本行已经放置皇后，扫描下一行
                
                //执行到这里，说明前面已经不满足条件了，需要移除皇后
                (*diagonal_col)[col] = true;//移除皇后，设置为true，意味着本列还可以继续放置皇后
                (*diagonal_right)[right] = true;
                (*diagonal_left)[left] = true;
                (*temp)[row][col] = '.';
            }//if
            
        }//for
    }//solve
    
    vector<vector<string>> solveNQueens(int n) {
        vector<bool> diagonal_col_(n,true);//列初始化为true，说明每一列都可以放置元素
        vector<bool> diagonal_right_(2*n-1,true);//主对角线都初始化true，说明可以放置皇后，注意这里“主”和“从”与矩阵相反
        vector<bool> diagonal_left_(2*n-1,true);//从对角线都初始化true，说明可以放置皇后
        vector<string> temp_(n,string(n,'.'));//临时结果集（n*n的矩阵）都赋值为.
        vector<vector<string>> ans_;//答案集
        
        nn = n;
        diagonal_col = &diagonal_col_;
        diagonal_right = &diagonal_right_;
        diagonal_left = &diagonal_left_;
        temp = &temp_;
        ans = &ans_;
        solve(0);//从第0行开始放置皇后
        return ans_;
    }
};
```
