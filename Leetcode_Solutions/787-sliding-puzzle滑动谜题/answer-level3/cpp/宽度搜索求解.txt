    class Solution {
    public:
        set<vector<vector<int>>> S;//记录已经处理过的情况
        bool panduan(vector<vector<int>>& board){//判断是否满足题意
            for(int i=0;i<5;++i){
                if(board[i/3][i%3]!=i+1)return false;
            }
            return true;
        }
        bool is(vector<vector<int>>& board){//判断情况是否出现过，如果没出现添加到集合里
            if(S.count(board)==0){
                S.insert(board);
                return true;
            }
            else return false;
        }
        void jiaohuan(int x0,int y0,int x1,int y1,vector<vector<int>>& temp){//交换瓦片
            int z=temp[x0][y0];
            temp[x0][y0]=temp[x1][y1];
            temp[x1][y1]=z;
        }
        queue<vector<vector<int>>> Q;
        queue<int> K,point;
        int slidingPuzzle(vector<vector<int>>& board) {
            if(panduan(board))return 0;
            while(!K.empty())K.pop();
        while(!Q.empty())Q.pop();
        while(!point.empty())point.pop();
            Q.push(board);
            K.push(0);
            int x,y;
            for(int i=0;i<2;i++)//记录0的位置
                for(int j=0;j<3;++j){
                    if(board[i][j]==0){
                        x=i;
                        y=j;
                        break;
                    }
                }
            point.push(x*3+y);
            int X,Y;
        while(!Q.empty()){//BFS
            vector<vector<int>> temp=Q.front();
            Q.pop();
            int k=K.front();
            K.pop();
            x=point.front()/3,y=point.front()%3;
            point.pop();
            k++;
            int X=(x+1)%2,Y=y;//上或者下
            jiaohuan(x,y,X,Y,temp);
            if(panduan(temp)){//如果符合条件退出，并返回步数
                return k;
            }
            else{
                    if(is(temp)){
                    Q.push(temp);
                    K.push(k);
                    point.push(X*3+Y);
                    }
                jiaohuan(x,y,X,Y,temp);
            }
            X=x;
            Y=y+1;//左移
            if(Y>=0 && Y<=2){
                jiaohuan(x,y,X,Y,temp);
                if(panduan(temp)){
                    return k;
                }
                else{
                    if(is(temp)){
                    Q.push(temp);
                    K.push(k);
                    point.push(X*3+Y);
                    }
                    jiaohuan(x,y,X,Y,temp);
                }
            }
            X=x;
            Y=y-1;//右移
            if(Y>=0 && Y<=2){
                jiaohuan(x,y,X,Y,temp);
                if(panduan(temp)){
                return k;
                }
                else{
                        if(is(temp)){
                    Q.push(temp);
                    K.push(k);
                    point.push(X*3+Y);
                    }
                    jiaohuan(x,y,X,Y,temp);
                }
            } 
        }
            return -1;
        }
    };