### 解题思路
1. 计算每个点的出度（下属个数）
2. 将出度为0 的点入队
3. 当队列非空，取队首元素，将父节点（直属上级）出度-1，如果上级出度也==0，那么将上级入队，循环直到队列非空


***这是典型的拓扑排序，将没有依赖的节点先访问，逐步拆图，直到剩下最后一个节点***
[refs:https://oi-wiki.org/graph/topo/](https://oi-wiki.org/graph/topo/)

### 代码

```cpp

typedef vector<int> VI;
typedef queue<int> QI;

#define FOR(i, L, R) for (int i = L; i < R; ++i)

class Solution {
    int numOfMinutes(int N, int headID, vector<int>& m, vector<int>& t) {
        VI edges(N); //记录每个点的出度
        VI sub(N);   //记录子节点需要花的最大时间
        FOR(i, 0, N) {
            if (m[i] != -1)
                edges[m[i]]++; //标记出度
        }
        QI q;
        FOR(i, 0, N) {
            if (!edges[i]) q.push(i); //出度为0 的入队
        }
        while (!q.empty()) {
            int x = q.front(); q.pop();
            int mx = m[x];
            if (mx == -1) break;
            sub[mx] = max(sub[x] + t[x], sub[mx]); //更新子节点中花的最长时间
            if (--edges[mx] == 0) q.push(mx);
        }
        return sub[headID] + t[headID];
    }
};

```