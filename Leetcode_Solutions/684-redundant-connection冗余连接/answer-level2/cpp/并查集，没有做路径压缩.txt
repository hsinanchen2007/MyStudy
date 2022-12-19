### 解题思路
并查集，没有做路径压缩

### 代码

```cpp
const int N = 1001;
class Solution {
public:
    int FindFatherNode(vector<int>& relationMap, int v)
    {
        if (relationMap[v] == v) {//上层节点就是自己，返回
            return v;
        }

        /*上层节点不是自己，向上递归查找，没有路径压缩*/
        int upperNode = relationMap[v];
        return FindFatherNode(relationMap, upperNode);
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        std::ios::sync_with_stdio(false);
        vector<int> ans = {0, 0};
        vector<int> relationMap(N, 0);
        for (int i = 0; i < N; ++i) {
            relationMap[i] = i;
        }

        for (auto& e : edges) {
            int node0 = e[0];
            int node1 = e[1];
            int fatherNode0 = FindFatherNode(relationMap, node0);          
            int fatherNode1 = FindFatherNode(relationMap, node1);
            /*两个集合的根节点不相等，将其中一个根节点的上层节点设置为另一个(顺序无所谓，目的仅仅是将两个集合合并)*/
            if (fatherNode0 != fatherNode1) {
                relationMap[fatherNode0] = fatherNode1;
            } else {/*两个集合根节点相等，因为题目已经保证了没有重复边，
            那说明从两个不同的节点出发均可抵达同一根节点，而且又是无向图，那么两个节点本身就是联通
            现在新的边又可以两个节点直达，说明一定存在环，而导致成环的边正是当前这条新边*/
                ans[0] = e[0];
                ans[1] = e[1];
                break;
            }
        }

        return ans;
    }
};
```