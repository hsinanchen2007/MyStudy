回溯求解
```
class Solution {
public:
    int totalNQueens(int n) {
        vector<string> tmp(n,string(n,'.'));
        int count=0;
        helper(count,tmp,0);
        return count;
    }
    void helper(int& count,vector<string> tmp,int i){
        if(i>=tmp.size()){
            count++;
            return;
        }
        for(int j=0;j<tmp.size();j++){
            if(isProper(tmp,i,j)){
                tmp[i][j]='Q';
                helper(count,tmp,i+1);
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