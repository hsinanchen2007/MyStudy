### 解题思路
开始用bfs来做，有个用例{0,1}，{0,2}，{1,2}没通过
后来改用dfs加记忆法才通过

### 代码

```cpp
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
    {
        nums = numCourses;
        
        for (auto each : prerequisites) {
            course[each.front()].push_back(each.back());
        }
        
        int result;
        vector<int> memo(nums, 0);
        vector<int> visited(nums, 0);
        
        for (int i = 0; i < numCourses; ++i) {
            result = dfs(i, visited, memo);
            if (result == 0) {
                return false;
            }
        }
        
        return true;
    }
private:
    unordered_map<int, vector<int>> course;
    int nums;
    
    int dfs(int one, vector<int>& visited, vector<int>& memo)
    {
        if (memo[one] != 0) {
            return memo[one];
        }
        
        if (visited[one] == 1) {
            return 0;
        } else {
            visited[one] = 1;
        }
        
        int result;
        for (int each : course[one]) {
            result = dfs(each, visited, memo);
            if (result == 0) {
                return 0;
            }
        }
        
        memo[one] = 1;
        visited[one] = 0;
        
        return 1;
    }
};
```