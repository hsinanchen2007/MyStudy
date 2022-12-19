
隐式图上的BFS，关键在于定义好状态和转移操作，没有什么坑。

```c++ []
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        queue<Node> que;
        unordered_map<string, bool> vis;
        for(auto it : deadends){
            vis[it] = true;
        }
        que.push(Node("0000", 0));
        while(que.size()){
            auto now = que.front();
            que.pop();
            if(now.state == target) return now.steps;
            if(vis[now.state]) continue;
            vis[now.state] = true;
            for(int i = 0;i < 4;i++){
                for(int j = -1;j < 2;j+=2){
                    string next_state(now.state);
                    int tmp = (next_state[i] - '0') + j + 10;
                    tmp %= 10;
                    next_state[i] = tmp +'0';
                    que.push(Node(next_state, now.steps+1));
                }
            }
        }
        return -1;
    }
private:
    struct Node{
        string state;
        int steps;
        Node(string _s, int _st):state(_s),steps(_st){}
    };
};
```