### 解题思路

BFS：
对着箱子找钥匙，对着钥匙找箱子。

执行用时 :144 ms, 在所有 C++ 提交中击败了54.22% 的用户
内存消耗 :34.8 MB, 在所有 C++ 提交中击败了5.20%的用户

### 代码

```cpp
class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        queue<int> Q;
        int n = initialBoxes.size();
        vector<bool> visited(status.size());
        int sum = 0;
        
        for(int init: initialBoxes) {
            Q.push(init);
        }
        
        unordered_set<int> Kdict;
        unordered_set<int> Bdict;
        while(!Q.empty()) {
            int size = Q.size();
            for(int i=0; i<size; i++) {
                int cur = Q.front();
                // cout << "Opening: " << cur << endl;
                sum += candies[cur];
                visited[cur] = true;
                Q.pop();
                Kdict.insert(keys[cur].begin(), keys[cur].end());
                Bdict.insert(containedBoxes[cur].begin(), containedBoxes[cur].end());

                for(int box: containedBoxes[cur]) {
                    if(visited[box])
                        continue;
                    if(status[box] == 1 || Kdict.count(box) > 0) {
                        Q.push(box);
                        visited[box] = true;
                    }
                }
                for(int key: keys[cur]) {
                    if(!visited[key] && Bdict.count(key) > 0) {
                        Q.push(key);
                        visited[key] = true;
                    }
                }
            }
        }
        return sum;
    }
};
```