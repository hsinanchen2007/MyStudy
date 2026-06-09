```
class Solution {
public:
vector<vector<string>>ans;
    vector<vector<string>> solveNQueens(int n) {
    vector<int>queen(n,-1);//记录皇后位置，queen[i]上的值表示放在第i行第j列
    Queens(0,n,queen);
    return ans;
    }
    void Queens(int row,int n,vector<int>&queen)
    {
        if(row==n)//此时皇后摆放完毕
        {
            vector<string>temp;
        for(int i=0;i<n;i++)
        {
            string now="";
            for(int j=0;j<n;j++)
            {
                if(j==queen[i])
                now+="Q";
                else
                now+=".";
            }
            temp.push_back(now);
        }
        ans.push_back(temp);
        }
        else
        {
            for(int col=0;col<n;col++)//遍历每一列，看第row行可以放在哪一列
            {
                queen[row]=col;
                if(isOk(row,n,queen))//如果该位置可行，递归摆放到下一行
                 Queens(row+1,n,queen);
            }
            //如果row行所有列都不能摆放，回溯到上一行
        }
    }
    bool isOk(int row,int n,vector<int>&queen)
    {
        for(int j=0;j<row;j++)//检查row之前的所有行，不出现在同一列/主、副对角线上
        {
            if(queen[row]==queen[j]||row-queen[row]==j-queen[j]||row+queen[row]==j+queen[j])
            return false;
        }
        return true;
    }
};
```
