bfs通常用队列来保存状态，但是这道题要处理回溯问题，用stack来保存状态，进栈、出栈的位置也发生改变。
```
class Solution {
public:

    struct node
    {
        int x,y,t;
        node(int xx,int yy,int tt):x(xx), y(yy), t(tt){}
    };

    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0; i<board.size(); i++)
        {
            for(int j=0; j<board[0].size(); j++)
            {
                if(board[i][j]==word[0])
                {
                    if(word.size()==1)
                    {
                        return true;
                    }
                    while(!st.empty()) st.pop();
                    node tem={i,j,0};
                    st.push(tem);
                    if(bfs(board.size(), board[0].size(), word, board, i, j))
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }

    bool bfs(int n, int m, string word, vector<vector<char>> board, int startx, int starty)
    {
        bool flag=false;
        vector<vector<bool>> g(n+1, vector<bool>(m+1,false));
        g[startx][starty]=false;
        while(!st.empty())
        {
            node f = st.top();st.pop();
            if(g[f.x][f.y]) 
            {
                g[f.x][f.y]=false;
                continue;
            }
            st.push(f);
            g[f.x][f.y]=true;
            int i;
            for(i=0; i<4; i++)
            {
                int x=dir[i].first+f.x;
                int y=dir[i].second+f.y;
                if(x>=0&&x<n&&y>=0&&y<m&&g[x][y]==false&&board[x][y]==word[f.t+1])
                {
                    node tem={x,y,f.t+1};
                    st.push(tem);
                    g[x][y]=false;
                    if((f.t+1)==(word.size()-1))
                    {
                        flag=true;
                        break;
                    }
                }
            }
            if(flag)
            {
                break;
            }
        }
        return flag;
    }

private:
    stack<node> st;
    vector<pair<int,int>> dir{{0,1},{0,-1},{1,0},{-1,0}};
};
```
