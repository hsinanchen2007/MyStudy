1、先排序，再回溯，这样只需要回溯到第一个就可以退出了
2、每张机票只能用一次，用map标记（注意起始-终点可能重复，所以key不能是起始-终点的string）

```
class Solution {
public:
    vector<string> res;
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        sort(tickets.begin(), tickets.end());
        unordered_map<int, int> visited;
        for (int index = 0; index < tickets.size(); ++index) {
            vector<string> it = tickets[index];
            if (it[0] == "JFK") {
                res.clear();
                visited.clear();
                res.push_back(it[0]);
                res.push_back(it[1]);
                visited[index]++;
                if (dfs(it[1], tickets, visited)) {
                    break;
                }
            }
        }

        return res;
    }

    bool dfs(string start, const vector<vector<string>> &tickets, unordered_map<int, int> &visited) {
        if (res.size() == tickets.size() + 1) {
            return true;
        }
        
        for (int index = 0; index < tickets.size(); ++index) {
            vector<string> it = tickets[index];
            if (it[0] == start && (visited.count(index) == 0)) {
                res.push_back(it[1]);
                visited[index]++;
                if (dfs(it[1], tickets, visited)) {
                    return true;
                }
                res.pop_back();
                visited.erase(index);
            }
        }
        return false;
    }
};
```
