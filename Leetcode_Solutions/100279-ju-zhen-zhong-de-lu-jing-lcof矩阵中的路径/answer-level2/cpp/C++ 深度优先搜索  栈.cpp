class Solution {
public:
    // 使用栈来进行DFS
    // footMat：记录足迹  一个辅助栈
    // 栈的内容  node（坐标，然后是当前的探索方向）  进栈条件  能走通  出栈条件  当前所有方向都已经探索完毕
    struct coordinate{
        int x;
        int y;
        coordinate(int a=0, int b=0){
            x = a;  y = b;
        }
    };
    struct node{
        coordinate p;
        int dir;  // d有0,1,2,3四种选择，代表上 右 下 左
    };
    stack<node> stk;
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int columns = board[0].size();
        if(word.size()>rows*columns)
            return false;
        int **footMat = new int*[rows];
        for(int i=0; i<rows; ++i){
            footMat[i] = new int[columns];
        }
        for(int i=0; i<rows; ++i){
            for(int j=0; j<columns; ++j)
                footMat[i][j] = 0;
        }
        int curIdx = 0;
        coordinate co;
        node n;
        int x, y;
        for(int i=0; i<rows; ++i){
            for(int j=0; j<columns; ++j){
                curIdx = 0;
                if(board[i][j]==word[curIdx]){// 找到入口
                    co.x = i;
                    co.y = j;
                    n.p = co;
                    n.dir = 0;
                    stk.push(n);
                    curIdx++;
                    footPrint(footMat, co, 1);
                    if(curIdx>=word.size())
                        return true;
                    while(true){
                        if(isPath(n, board, word, footMat, curIdx)){
                            curIdx++;
                            if(curIdx>=word.size())
                                return true;
                            switch(n.dir){
                                case 0: x=n.p.x-1; y=n.p.y; break;
                                case 1: x=n.p.x; y=n.p.y+1; break;
                                case 2: x=n.p.x+1; y=n.p.y; break;
                                case 3: x=n.p.x; y=n.p.y-1; break;
                            }
                            co.x = x;
                            co.y = y;
                            footPrint(footMat, co, 1);
                            n.p = co;
                            n.dir = 0;
                            stk.push(n);
                        }
                        else{
                            n.dir++; // 换一个方向探索
                            stk.pop(); // 
                            stk.push(n); // 更新了n.dir后要更新顶部元素  很重要，要不退栈的时候会出错
                        }
                        while(n.dir==4){ // 当前不行
                            n = stk.top();
                            footPrint(footMat, n.p, 0);  //消除足迹  // =1有76个通过
                            stk.pop();    // 退栈
                            if(stk.empty()){
                                break;
                            }
                            n = stk.top();
                            n.dir++;
                            curIdx--;
                            stk.pop(); // 
                            stk.push(n); // 更新了n.dir后要更新顶部元素  很重要，要不退栈的时候会出错
                        }
                        if(stk.empty())
                            break;
                    }
                }
            }
        }
        return false;
    }

    bool isPath(node n, vector<vector<char>>& board, string& word, int** footMat, int curIdx){
        int x, y;
        int rows = board.size();
        int columns = board[0].size();
        switch(n.dir){
            case 0: x=n.p.x-1; y=n.p.y; break;
            case 1: x=n.p.x; y=n.p.y+1; break;
            case 2: x=n.p.x+1; y=n.p.y; break;
            case 3: x=n.p.x; y=n.p.y-1; break;
        }
        if(x<0 || x>=rows || y<0 || y>=columns){  // 范围不对
            return false;
        }
        if(footMat[x][y]==1) // 已经走过
            return false;
        if(board[x][y]!=word[curIdx])  // 不匹配
            return false;
        return true;
    }

    void footPrint(int** footMat, coordinate co, int value){
        footMat[co.x][co.y] = value;
    }

};