```c++
class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        vector<vector<char>>board(8,vector<char>(8,'.'));
        int n = queens.size(),x=king[0],y=king[1];
        board[x][y]='K';
        vector<vector<int>>res;
        for(int i=0;i<n;i++)board[queens[i][0]][queens[i][1]]='Q';
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                if(board[i][j]=='Q'){
                    if(i==x){//同行
                        int flag=1;
                        for(int k=min(j,y)+1;k<max(j,y);k++){
                            if(board[i][k]=='Q'){
                                flag=0;
                                break;
                            }
                        }
                        if(flag)res.push_back({i,j});
                    }else if(j==y){//同列
                        int flag = 1;
                        for(int k=min(i,x)+1;k<max(i,x);k++){
                            if(board[k][j]=='Q'){
                                flag=0;
                                break;
                            }
                        }
                        if(flag)res.push_back({i,j});
                    }else if(abs(i-x)==abs(j-y)){//同对角线
                        int flag=1,flag1=1,flag2=1;//默认斜右下走
                        if(i<x&&j>y)flag2=-1;//向左下走
                        else if(i>x&&j>y)flag1=-1,flag2=-1;//向左上走
                        else if(i>x&&j<y)flag1=-1;//向右上走
                        for(int k=1;k<abs(i-x);k++){
                            if(board[i+k*flag1][j+k*flag2]=='Q'){
                                flag=0;
                                break;
                            }
                        }
                        if(flag)res.push_back({i,j});

                    }else continue;
                }else continue;
            }
        }
        return res;
    }
};
```