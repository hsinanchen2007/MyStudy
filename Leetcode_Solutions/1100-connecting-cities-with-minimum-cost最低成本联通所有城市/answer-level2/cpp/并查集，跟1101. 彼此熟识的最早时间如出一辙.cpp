### 解题思路
并查集，跟1101. 彼此熟识的最早时间如出一辙，唯一不同是1101是求成圈的那条边的时间，这个是要把前面所有边的费用加起来

### 代码

```cpp
class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b)
    {
        if (a[2] < b[2]) {
            return true;
        } else {
            return false;
        }
    }

    int GetRoot(vector<int>& relationMap, int v)
    {
        if (relationMap[v] == v) {
            return v;
        }

        int upperNode = relationMap[v];
        relationMap[v] = GetRoot(relationMap, upperNode);
        
        return relationMap[v];
    }

    int minimumCost(int N, vector<vector<int>>& connections) {
        std::ios::sync_with_stdio(false);
        if (N < 2) {
            return -1;
        }

        sort(connections.begin(), connections.end(), cmp);
        vector<int> relationMap(N + 1, 0);
        for (int i = 0; i < relationMap.size(); ++i) {
            relationMap[i] = i;
        }

        int sum = 0;
        for (auto& c : connections) {
            int rootNode1 = GetRoot(relationMap, c[0]);
            int rootNode2 = GetRoot(relationMap, c[1]);
            if (rootNode1 != rootNode2) {
                relationMap[rootNode1] = rootNode2;
                sum += c[2];
                --N;
                if (N <= 1) {
                    return sum;
                }
            }
        }

        return -1;
    }
};
```