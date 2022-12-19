1. 判断入参异常情况
- 输入小于0，edges为空
- 如果source不在节点中返回false
- 如果destination下还有其他节点返回false
2. DFS深度遍历
- 如果source和destination相同，结束，注意如果这个时候没有访问一个节点，终止
- source是否在图中有下一个节点，如果没有，终止
- 如果又一次访问相同节点，则存在环
- 对下一层节点进行DFS深度遍历
3. 每一次遍历保存的visited容易请保持独立，逐层追加传递
```
class Solution
{
public:
    bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination)
    {
        if (n < 0 || edges.empty()) {
            return true;
        }

        if (!initializeGraph(edges)) {
            return false;
        }

        if (gragh.find(source) == gragh.end()) {
            return false;
        }

        if (gragh.find(destination) != gragh.end()) {
            return false;
        }

        set<int> visited;

        return leadsToDestinationDfs(source, visited, destination);
    }

    bool initializeGraph(vector<vector<int>> &edges)
    {
        for (int i = 0; i < edges.size(); ++i) {
            vector<int> & pair = edges.at(i);
            if (pair.size() < 2) {
                return false;
            }

            int key = pair.at(0);
            int value = pair.at(1);
            cout << key << "," << value << endl;
            map<int, vector<int>>::iterator finder = gragh.find(key);
            if (finder != gragh.end()) {
                finder->second.push_back(value);
            } else {
                vector<int> values;
                values.push_back(value);
                gragh.insert(make_pair(key, values));
            }
        }
        return true;
    }

    bool leadsToDestinationDfs(int source,  set<int> visited, int destination)
    {
        if (source == destination) {
            if (visited.empty()) {
                cout << source << "," << destination << " visited empty false" << endl;
                return false;
            }
            return true;
        }

        map<int, vector<int>>::iterator finder = gragh.find(source);
        if (finder == gragh.end()) {
            cout << source << "," << destination << " key not exsit false" << endl;
            return false;
        }

        if (visited.find(finder->first) != visited.end()) {
            cout << source << "," << destination << " visited false" << endl;
            return false;
        }

        visited.insert(finder->first);

        vector<int > const & values = finder->second;
        for (vector<int>::const_iterator iter = values.begin();
                iter != values.end();
                ++iter) {

            if (!leadsToDestinationDfs(*iter, visited, destination)) {
                return false;
            }
        }

        return true;
    }
private:
    map<int, vector<int>> gragh;
};
```
