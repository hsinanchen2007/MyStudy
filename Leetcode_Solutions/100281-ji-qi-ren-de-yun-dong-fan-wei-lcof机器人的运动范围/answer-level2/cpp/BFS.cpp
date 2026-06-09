### 解题思路
BFS

### 代码

```cpp
class Solution {
public:
    int movingCount(int m, int n, int k) {
        vector<vector<int>>visited(m, vector<int>(n, 0));//创建visit数组，标记每个点是否访问过
        queue<pair<int, int>> q;//队列，存储符合要求的x,y
        q.push({0, 0});//初始位置必定符合要求
        int count = 0;
        visited[0][0] = 1;
        while(!q.empty()){
            auto front = q.front();//获取队头元素
            q.pop();//出队
            int x = front.first;
            int y = front.second;
            count += 1;
            for(auto d : directions){
                int next_x = x + d.first;
                int next_y = y + d.second;
                if(next_x < 0 || next_x >= m || next_y < 0 || next_y >= n || visited[next_x][next_y] == 1 || sumDigit(next_x, next_y) > k){
                    continue;
                }//如果该点未访问过且数位之和大于k则跳过
                q.push({next_x, next_y});//否则说明该点是能访问的点，将其加入队列
                visited[next_x][next_y] = 1;//并将该位置标记为已访问过。
            }
        }
        return count;
    }
    int sumDigit(int x, int y){
        int sum = 0;
        while(x > 0){
            sum += x % 10;
            x /= 10;
        }
        while(y > 0){
            sum += y % 10;
            y /= 10;
        }
        return sum;
    }
    private:
    vector<pair<int, int>>directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
};
```