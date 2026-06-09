```
class Solution {  
public:  
    struct Node {  
        int x;  
        int y;  
        Node(int i, int j) : x(i), y(j) {}  
        bool operator<(const Node &other) const {  
            if (x < other.x) {  
                return true;  
            } else if (x == other.x) {  
                return y < other.y;  
            }  
            return false;  
        }  
        Node() {}  
    };  
  
    struct Route {  
        int step;  
        string way;  
        Route(int l, string w) : step(l), way(w) {}  
        Route() {}  
    };  
      
    int GetNextPoint(Node &node, vector<vector<int>>& maze, int d, Node &next)  
    {  
        int dir[][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};  
        int nx = node.x;  
        int ny = node.y;  
          
        next.x = nx;  
        next.y = ny;  
        int step = 0;  
        while(true) {  
            nx = nx + dir[d][0];  
            ny = ny + dir[d][1];  
            if ((nx < 0) || (nx >= maze.size()) || (ny < 0) || (ny >= maze[0].size()) || (maze[nx][ny] == 1)) {  
                break;  
            }  
            next.x = nx;  
            next.y = ny;  
            step++;  
            if (maze[nx][ny] == 2) {  
                break;  
            }  
        }  
        return step;  
    }  
  
    string findShortestWay(vector<vector<int>>& maze, vector<int>& ball, vector<int>& hole) {  
        int m = maze.size();  
        int n = maze[0].size();  
        char dir[] = {'u', 'd', 'l', 'r'};  
        maze[hole[0]][hole[1]] = 2;  
        queue<Node> q;    
        map<Node, Route> visit;   
          
        Node ballNode(ball[0], ball[1]);  
        Route route(0, "");  
        q.push(ballNode);  
        visit[ballNode] = route;  
  
        while(!q.empty()) {  
            Node srcP = q.front();  
            Route srcRoute = visit[srcP];  
            q.pop();  
            for (int i = 0; i < 4; i++) {  
                Node dstP;  
                int nextStep = GetNextPoint(srcP, maze, i, dstP);  
                if (nextStep == 0) {  
                    continue;  
                }  
                int totalStep = srcRoute.step + nextStep;  
                string totalWay = srcRoute.way + dir[i];  
                if (visit.count(dstP) == 0) {  
                    Route route(totalStep, totalWay);  
                    visit[dstP] = route;  
                    q.push(dstP);  
                } else {  
                    Route &route = visit[dstP];  
                    if ((totalStep < route.step) || ((totalStep == route.step) && (totalWay < route.way))) {  
                        route.step = totalStep;  
                        route.way = totalWay;  
                        q.push(dstP);  
                    }  
                }  
            }  
        }   
  
        Node holeNode(hole[0], hole[1]);  
        if (visit.count(holeNode) == 0) {  
            return "impossible";  
        } else {  
            return visit[holeNode].way;  
        }  
    }  
};  
```
