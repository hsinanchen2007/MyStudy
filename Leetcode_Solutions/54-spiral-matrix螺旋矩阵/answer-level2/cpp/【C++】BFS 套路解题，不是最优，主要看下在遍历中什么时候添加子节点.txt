1.从左到右 唯一
2.从上到下 唯一
3.从右到左 唯一
4.从下到上到时候，需要将所有节点遍历完，才可以回到下一层，重复1～4步骤
```
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if (matrix.empty()) {
            return result;
        }
        if (matrix.at(0).empty()) {
            return result;
        }
        
        int m = matrix.size();
        int n = matrix.at(0).size();
        
        vector<vector<int>> visited(m, vector<int>(n, false));
        queue<pair<int, int>> pathQueue;
        pathQueue.push({0,0});
        visited[0][0] = true;                        
        while (!pathQueue.empty()) {
            pair<int, int> current;
            while (!pathQueue.empty()) {
                current = pathQueue.front();
                pathQueue.pop();
                result.push_back(matrix[current.first][current.second]);   
            }
             
            if (current.second + 1 < n && !visited[current.first][current.second + 1]) {
                pathQueue.push({current.first, current.second + 1});
                visited[current.first][current.second + 1] = true;  
                continue;
            }
            
            if (current.first + 1 < m && !visited[current.first + 1][current.second]) {
                pathQueue.push({current.first + 1, current.second});
                visited[current.first + 1][current.second] = true;  
                continue;
            }
 
            if (current.second - 1 >= 0 && !visited[current.first][current.second - 1]) {
                pathQueue.push({current.first, current.second - 1});
                visited[current.first][current.second - 1] = true;  
                continue;
            }
            
            while ((current.first - 1 >= 0) && !visited[current.first - 1][current.second]) {
                pathQueue.push({current.first - 1, current.second});
                visited[current.first - 1][current.second] = true;  
                current.first -= 1;
            }
        }
        return result;
    }
};
```
