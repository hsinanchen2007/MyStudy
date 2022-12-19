### 解题思路
这是我第一个BFS代码
探测
没有回溯也没有用剪纸

### 代码

```cpp
class Solution {
private:
    queue<int> myque_col;
    queue<int> myque_row;
    int step;
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        // BFS
        // 无需判断该点是否走过
        // 入队条件：当前路径小于现有路径，不为墙
        // 终止条件：队列空
        if(rooms.size() > 0){
            if(rooms[0].size()>0){
                step = 0;
                for(int i=0; i<rooms.size(); ++i)
                    for(int j=0; j<rooms[i].size(); ++j)
                        if(rooms[i][j] == 0){
                            myque_col.push(i);
                            myque_row.push(j); //坐标点入栈
                        }// 找到所有可能开始的门
                int tag; //指示该轮路径
                while(!myque_col.empty()){
                    tag = myque_col.size();
                    ++step;
                    for(int cur=0;cur<tag;++cur){
                        if(myque_row.front() > 0) getpath(rooms, myque_col.front(), myque_row.front()-1); // 左
                        if(myque_col.front() > 0) getpath(rooms, myque_col.front()-1, myque_row.front()); // 上
                        if(myque_col.front() < rooms.size() - 1) getpath(rooms, myque_col.front()+1, myque_row.front()); // 下
                        if(myque_row.front() < rooms[0].size()-1) getpath(rooms, myque_col.front(), myque_row.front()+1); // 右
                        myque_col.pop(); 
                        myque_row.pop();//出队
                    }// 四个方向
                }//对队列的元素BFS
            }// 判断数据相邻接的关系需要坐标点
            
            
        }//当队伍不空的时候
    }
    void getpath(vector<vector<int>>& nums, int col_cur, int row_cur){
        // 改变四个方向值
        if(nums[col_cur][row_cur] != -1 && nums[col_cur][row_cur] > step){
            nums[col_cur][row_cur] = step;
            myque_col.push(col_cur);
            myque_row.push(row_cur);
        }
    }//改变room值
};
```