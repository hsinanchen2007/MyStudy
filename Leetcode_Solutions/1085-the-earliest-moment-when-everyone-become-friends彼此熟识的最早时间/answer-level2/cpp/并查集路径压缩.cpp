### 解题思路
典型并查集的题目，两个要点：
1：按建交时间升序排列，这样比较容易获得全部成为朋友的最早时间
2：每找到一次关系则圈子数减1，什么时候只剩1个圈子了说明大家都是朋友了
3：路径压缩加快查找速度
### 代码

```cpp
class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b)
    {
        if (a[0] < b[0]) {
            return true;
        } else {
            return false;
        }
    }

    int FindRootNode(vector<int>& relationMap, int v)
    {
        if (relationMap[v] == v) {
            return v;
        }

        int upperNode = relationMap[v];
        /*顺便路径压缩能让查找速度快不少*/
        relationMap[v] = FindRootNode(relationMap, upperNode);

        return relationMap[v];
    }

    int earliestAcq(vector<vector<int>>& logs, int N) {
        std::ios::sync_with_stdio(false);
        sort(logs.begin(), logs.end(), cmp);//按建交时间升序排列，这样比较容易获得全部成为朋友的最早时间
        vector<int> relationMap(N + 1, 0);
        for (int i = 0; i <= N; ++i) {
            relationMap[i] = i;
        }

        for (auto& l : logs) {
            int rootNode1 = FindRootNode(relationMap, l[1]);
            int rootNode2 = FindRootNode(relationMap, l[2]);
            if (rootNode1 != rootNode2) {
                relationMap[rootNode1] = rootNode2;//建交
                --N;
                if (N <= 1) {//初始化为N个独立的圈子，每找到一层关系则圈子数减1，什么时候只剩1个圈子了说明大家都是朋友了
                    return l[0];
                } 
            }
        }

        return -1;
    }
};
```