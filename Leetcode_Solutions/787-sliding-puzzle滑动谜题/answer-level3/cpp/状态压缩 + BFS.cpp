### 解题思路

执行用时 :12 ms, 在所有 C++ 提交中击败了73.25% 的用户
内存消耗 :11 MB, 在所有 C++ 提交中击败了44.12%的用户

### 代码

```cpp
class Node {
public:
    int r;
    int c;
    string state;
    Node(int rr, int cc, string ss): r(rr), c(cc), state(ss) {}
};

class Solution {
private:
    unordered_map<string, string> path;
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string ss = serialize(board);
        if(isValid(ss))
            return 0;
        
        int r, c;
        for(int i=0; i<2; i++)
            for(int j=0; j<3; j++) {
                if(board[i][j] == 0) {
                    r = i;
                    c = j;
                }
            }
        queue<Node> Q;
        unordered_map<string, bool> visited;
        int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        Node initState(r, c, ss);
        Q.push(initState);
        visited[ss] = true;
        
        int level = 0;
        while(!Q.empty()) {
            int n = Q.size();
            level++;
            for(int j=0; j<n; j++) {
                auto cur = Q.front();
                Q.pop();
            
                for(int i=0; i<4; i++) {
                    int nx = cur.r + dir[i][0];
                    if(nx < 0 || nx > 1)
                        continue;
                    int ny = cur.c + dir[i][1];
                    if(ny < 0 || ny > 2)
                        continue;
                    int old_pos = cur.r * 3 + cur.c;
                    int new_pos = nx * 3 + ny;
                    string nss = cur.state;
                    std::swap(nss[old_pos * 2], nss[new_pos * 2]);
                    // 这里是正确步数，不必入队直接返回
                    if(isValid(nss)) {
                        path[nss] = cur.state;
                        printPath(nss, ss);
                        return level;
                    }
                    if(visited.count(nss) == 0) {
                        Node next(nx,ny, nss);
                        Q.push(next);
                        visited[nss] = true;
                        path[nss] = cur.state;
                    }
                }
            }
        }
        return -1;
    }
    
    void printPath(string& end, string& start) {
        stack<string> st;
        while(end != start) {
            st.push(end);
            end = path[end];
        }

        st.push(start);
        while(!st.empty()) {
            cout << st.top() << endl;
            st.pop();
        }
        cout << "=======================" << endl;
    }
    
    string serialize(vector<vector<int>>& board) {
        string bs;
        for(int i=0; i<2; i++)
            for(int j=0; j<3; j++) {
                bs.append(to_string(board[i][j]));
                bs.push_back('#');
            }
        return bs;
    }
    
    bool isValid(string& state) {
        return state == "1#2#3#4#5#0#";
    }
};
```