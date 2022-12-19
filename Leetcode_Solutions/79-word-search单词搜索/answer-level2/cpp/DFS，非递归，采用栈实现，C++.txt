```cpp []
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size();
        int col = board[0].size();
        int len = word.size();
        
        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
            {
                if(board[i][j] == word[0])
                {
                    vector<vector<int>> visited(row, vector<int>(col, -1));
                    stack<int> stack_x;
                    stack<int> stack_y;
                    int index = 0;
                    stack_x.push(i);
                    stack_y.push(j);
                    while(!stack_x.empty())
                    {
                        int x = stack_x.top();
                        int y = stack_y.top();                    

                        char w = board[x][y];
                        if(visited[x][y] > -1)
                        {
                            stack_x.pop();
                            stack_y.pop();
                            
                            index = visited[x][y];
                            visited[x][y] = -1;
                            continue;
                        }
                        if(w != word[index])
                        {
                            stack_x.pop();
                            stack_y.pop();                            
                            continue;
                        }
                        if(w == word[index])
                        {
                            visited[x][y] = index;

                            index++;
                            
                            //把相邻节点压入栈
                            if(x >= 1)
                            {
                                if(! (visited[x - 1][y] > -1))
                                {
                                    int upPos[2] = {x - 1, y};
                                    stack_x.push(x-1);
                                    stack_y.push(y);
                                }
                            }
                            if(x <= row - 2)
                            {
                                if(! (visited[x + 1][y] > -1))
                                {
                                    int downPos[2] = {x + 1, y};
                                    stack_x.push(x+1);
                                    stack_y.push(y);
                                }
                            }
                            if(y >= 1)
                            {
                                if(! (visited[x][y - 1] > -1))
                                {
                                    int leftPos[2] = {x, y - 1};
                                    stack_x.push(x);
                                    stack_y.push(y-1);
                                }
                            }
                            if(y <= col - 2)
                            {
                                if(! (visited[x][y + 1] > -1))
                                {
                                    int rightPos[2] = {x, y + 1};
                                    stack_x.push(x);
                                    stack_y.push(y+1);
                                }
                            }
                        }
                        if(index == len)return true;
                    }
                }

            }
        }

        return false;
    }


};
```