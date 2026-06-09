```
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<pair<int, char>, vector<pair<int, char>>> pq;
        
        map<char, int> mapChar;

        for (auto &t : tasks) mapChar[t]++;

        for (auto &m : mapChar) pq.push({m.second, m.first});

        vector<pair<int, char>> result;
        int lastIndex = 0;

        while (!pq.empty()) {
            for (int i = 0; i <= n; i++) {
                if (!pq.empty()) {
                    result.push_back(pq.top());
                    pq.pop();
                }
                else {
                    result.push_back({0, '#'});
                }
            }

            for (int i = lastIndex; i <= lastIndex + n; i++) {
                result[i].first--;
                
                if (result[i].first > 0 && result[i].second != '#') {
                    pq.push(result[i]);
                }
            }

            lastIndex += n + 1;
        }

        int index = result.size() - 1;
        for (; index >= 0; index--) {
            if (result[index].second != '#') break;
        }

        return index + 1;
    }
};
```
