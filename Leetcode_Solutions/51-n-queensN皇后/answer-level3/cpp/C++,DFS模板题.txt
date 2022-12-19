```
class Solution {
public:
    bool isValid(int n,int row,int col,vector<string>&list){
        //按行判断是否合法
        for(int i=0;i<row;i++){
            if(list[i][col]=='Q')return false;
        }
        //按列判断是否合法
        for(int i=0;i<n;i++){
            if(list[row][i]=='Q')return false;
        }
        //下面两个是判断斜对角线是否符合条件
        for(int i=row,j=col;i>=0&&j>=0;i--,j--){
            if(list[i][j]=='Q')return false;
        }
        for(int i=row,j=col;i>=0&&j<n;i--,j++){
            if(list[i][j]=='Q')return false;
        }
        return true;
    }
    void dfs(int n,int row,vector<string>&list,vector<vector<string>>&ans){//我们按照行进行放入元素
        if(row==n){//递归终止条件
            ans.push_back(list);
            return;
        }
        for(int col=0;col<n;col++){
            if(isValid(n,row,col,list)){//先判断再做选择
                //做选择
                list[row][col]='Q';
                //进入下一个决策
                dfs(n,row+1,list,ans);
                //撤销选择，回溯法
                list[row][col]='.';
            }
        }

    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>list(n,string(n,'.'));
        //vector<string>list;
        dfs(n,0,list,ans);//不存在访问过的问题，这里剪枝的条件是行列对角线不能有相同的皇后
        return ans;
    }
};
```
