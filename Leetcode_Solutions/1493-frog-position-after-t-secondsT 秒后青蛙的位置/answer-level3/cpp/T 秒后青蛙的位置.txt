层次遍历 
如果target == 当前的节点 
判断当前level == t || levet < t && no child 则返回计算好的概率值buf[tmp] 否则返回0.0
运行时间12ms 击败 98.75%
```c++
const int MAXN =150;
vector<int> edge[MAXN];
double buf[MAXN];
class Solution {
public:
    double BFS(int n, int t, int target){
        queue<int> Q; while(!Q.empty()) Q.pop();
        Q.push(1); buf[1] = 1; 
        int now = 0, cur = 0, Code = 1, nextCode = 0;
        while(!Q.empty()){
            int tmp = Q.front(); Q.pop();
            int child_cnt = 0;
            for(auto x : edge[tmp])
                if(buf[x] == 0.0) child_cnt++;
            if(tmp == target){
                if(now == t) return buf[tmp];
                else if(now < t){
                    if(child_cnt == 0) return buf[tmp];
                }
                else return 0.0;
            }
            for(auto e : edge[tmp]){
                if(buf[e] != 0.0) continue;
                buf[e] = buf[tmp] / child_cnt;
                nextCode++;
                Q.push(e);
            }
            if(++cur == Code){
                cur = 0; Code = nextCode; nextCode = 0;
                now++;
            }
        }
        return 0.0;
    }
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        for(int i = 0; i <= n; i++){
            buf[i] = 0.0;
            edge[i].clear();
        }
        for(auto e : edges){
            edge[e[0]].push_back(e[1]);
            edge[e[1]].push_back(e[0]);
        }
        return BFS(n, t, target);
    }
};
```