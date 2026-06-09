**关键思路：**
1、图的深度优先遍历，找到一个欧拉通路，沿一条路能够遍历所有节点；
2、题目保证至少有一条路，所以可以改造visited数组，当子节点不能继续遍历下去的话，返回父节节点，并将这个节点置为visited[i]=0,在叔叔节点间继续查找；
3、使用map<string,vector<string>>邻接表方法存储图，节省空间，动态增加节点(注意J->K可能有多张机票，因此用vector存储）；
4、深优遍历需要保存的标记：visited字典：保存机票是否使用过，cur：当前遍历过的机票数量；size：机票总数量；（由于没有异常值，一旦遍历的机票数量等于总数量时，即可返回机票列表，），travelList：路径数组，从深优遍历的叶子节点开始存储，直到返回根节点，遍历完要翻转。


**提交代码：**
```
class Solution {
   public:
    // 创建邻接表adjMap，创建等大小元素为bool类型的visited备忘录，
    void creatAdjMap(const vector<vector<string>>& tickets,
                     map<string, vector<string>>& adjMap,
                     map<string, vector<bool>>& visited) {
        // 创建邻接表
        for (int i = 0; i < tickets.size(); ++i) {
            const string& from = tickets[i][0];
            const string& to = tickets[i][1];
            adjMap[from].push_back(to);
        }
        // 创建备忘，初始为零
        for (auto& val : adjMap) {
            // 将adjMap的每行目的地排序
            sort(val.second.begin(), val.second.end());
            visited[val.first] = vector<bool>(val.second.size(), false);
        }
        return;
    }

    // 递归深度优先搜索
    bool dfs(map<string, vector<string>>& adjMap,
             map<string, vector<bool>>& visited,
             const string from,
             vector<string>& travelList,
             int& cur,
             int& size) {
        if (adjMap.count(from) != 0) {
            // 如果from是某个机票出发地，则判断是否遍历完所有地点
            bool allVisited = true;
            if (cur == size) {
                travelList.push_back(from);
                return true;
            }
            // cout << "from: " << from << endl;
            for (int i = 0; i < adjMap[from].size(); ++i) {
                if (visited[from][i] == false) {
                    cur++;
                    visited[from][i] = true;
                    if (dfs(adjMap, visited, adjMap[from][i], travelList, cur,
                            size)) {
                                // 子节点是欧拉通路，则将自己放入输出数组中，返回
                        travelList.push_back(from);
                        return true;
                    } else {
                        // 如果此路不同，则清楚访问标记，当前访问地点-1
                        cur--;
                        visited[from][i] = false;
                    }
                }
            }
            return false;
        }
        // 如果访问了所有的目的地，则返回
        if (cur == size) {
            travelList.push_back(from);
            return true;
        }
        // 尚未访问所有目的地，则此路不同，返回
        return false;
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        map<string, vector<bool>> visited;
        map<string, vector<string>> adjMap;
        int toNums = 0;
        creatAdjMap(tickets, adjMap, visited, toNums);

        vector<string> travelList;
        int cur = 1;
        int size = tickets.size() + 1;
        dfs(adjMap, visited, "JFK", travelList, cur, size);
        // travelList.push_back("JFK");
        reverse(travelList.begin(), travelList.end());
        return travelList;
    }
};
```
