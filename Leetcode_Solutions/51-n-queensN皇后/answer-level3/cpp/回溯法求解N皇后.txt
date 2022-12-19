回溯法求解，注意在判断是否可以放皇后的位置时候，我们从四个方向进行判断，在进行主对角线和次对角线判断时候，从当前位置逐渐接近左上方和右上方，而不是从左上方或者右上方直接接近当前位置（这样导致多解，因为这样可能由于判断条件提前终止而导致没有判断完毕，因此需要避免），求解即可。
```
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> tmp(n,string(n,'.'));
        vector<vector<string> > res;
        helper(res,tmp,0);
        return res;
    }
    void helper(vector<vector<string> >& res,vector<string> tmp,int i){
        if(i>=tmp.size()){
            res.push_back(tmp);
            return;
        }
        for(int j=0;j<tmp.size();j++){
            if(isProper(tmp,i,j)){
                tmp[i][j]='Q';
                helper(res,tmp,i+1);
                tmp[i][j]='.';
            }
        }
        
    }
    bool isProper(vector<string> tmp,int x,int y){
        for(int i=0;i<x;i++){
            if(tmp[i][y]=='Q') return false;
        }
        for(int j=0;j<y;j++){
            if(tmp[x][j]=='Q') return false;
        }
        for(int i=x-1,j=y-1;i>=0 && j>=0;i--,j--){
            if(tmp[i][j]=='Q') return false;
        }
        for(int i=x-1,j=y+1;i>=0 && j<tmp.size();i--,j++){
            if(tmp[i][j]=='Q') return false;
        }
        return true;
    }
};
```
