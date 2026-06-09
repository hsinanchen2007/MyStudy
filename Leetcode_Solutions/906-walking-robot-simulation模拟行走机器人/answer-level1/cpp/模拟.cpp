class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        
        // 当前方位  0北 1东 2南 3西
        int curDirct = 0; 
        // 北(0,1), 东(1,0), 南(0, -1), 西(-1, 0)
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};
        
        int x = 0, y = 0;
        
        // 将障碍点放在一个set容器中
        set<pair<int, int> > obj;
        for (vector<int> obstacle: obstacles) {
            obj.insert(make_pair(obstacle[0], obstacle[1])); //第i个障碍点
        }
        
        int ans = 0;
        for (int j = 0; j < commands.size(); j++) {
            if (commands[j] == -1) { // 向右转
                curDirct = (curDirct + 1) % 4;
            } else if (commands[j] == -2) { // 向左转
                curDirct = (curDirct + 3) % 4;
            } else { // 向前移动
                for (int k = 0; k < commands[j]; k++) {
                     int nx = x + dx[curDirct];
                     int ny = y + dy[curDirct];
                    if (obj.find(make_pair(nx, ny)) == obj.end()) {
                        x = nx;
                        y = ny;
                        ans = max(ans, x*x + y*y);
                    }
                }
            }
        }
        return ans;
        
    }
};