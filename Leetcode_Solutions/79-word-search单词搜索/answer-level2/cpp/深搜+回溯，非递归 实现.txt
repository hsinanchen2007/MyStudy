使用栈实现非递归深搜，在访问完一个节点所有子节点之后再弹栈，并置访问记录为false
实现代码：
```C++
//访问记录
bool tmcFlag[1010][1010];

//栈中的节点，记录坐标以及子节点的搜索状态
//times表示已经搜索的子节点数
//times为4时表示所有子节点均已搜索完毕，弹栈并回溯
struct Node{
    int x;
    int y;
    int times;
    Node(int x, int y, int times):x(x),y(y),times(times){};
};

//方向向量
int directionX[4] = {1,0,-1,0};
int directionY[4] = {0,1,0,-1};

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        //LeetCode是多点判别，需要在每个测试用例执行前重置访问记录
        memset(tmcFlag, false, sizeof(tmcFlag));
        //遍历board表，寻找深搜起始点
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                if(board[i][j] == word[0]){
                    if(DFS(board, i, j, word) == true)
                        return true;
                }
            }
        }
        return false;
    }
    bool DFS(vector<vector<char>>& board, int startX, int startY, string word){
        //模拟系统栈，记录搜索路径
        stack<Node*> sysSta;
        int lengthX = board.size(), lengthY = board[0].size();
        //搜索的层数，用来定位word中对应字母
        int index = 1;
        //起始点访问标记，将起始点压栈
        tmcFlag[startX][startY] = true;
        sysSta.push(new Node(startX,startY,0));
        //栈空表示起始点出发所有路径均搜索完毕
        while(!sysSta.empty()){
            //找到满足路径，直接退出
            if(index == word.size())
                return true;
            Node* top = sysSta.top();
            int topX = top->x, topY = top->y;
            //times==4时表示所有子节点均搜索完毕，弹栈并进行回溯
            if(top->times == 4){
                sysSta.pop();
                tmcFlag[topX][topY] = false;
                index--;
                //释放空间
                delete top;
            }else{
                //根据已搜索过的子节点数判断下一个搜索的方向
                int nextX = topX+directionX[top->times], nextY = topY+directionY[top->times];
                if(0 <= nextX && nextX < lengthX && 0 <= nextY && nextY < lengthY){
                    if(tmcFlag[nextX][nextY] == false && board[nextX][nextY] == word[index]){
                        tmcFlag[nextX][nextY] = true;
                        sysSta.push(new Node(nextX, nextY, 0));
                        index++;
                    }
                }
                top->times++;
            }
        }
        //将起始点搜索记录重置
        tmcFlag[startX][startY] = false;
        return false;
    }
};
```

对比通常情况，本题需要搜索所有不同路径，而非所有不同节点。
因此不能弹栈再将所有子节点一次性压入栈中。
需要在所有子节点搜索完毕后再弹栈，并进行回溯

