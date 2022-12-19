**首先，我们对每个节点维护一个最大剩余步数的数组 max_left**
因为我们是从0节点开始遍历的，所以，max[0] = M
这时的max_left = [6, -1, -1],初始值设为-1。
**之后我们会通过广度优先的遍历方式维护这个数组。**
通过广度优先遍历，更新这个数组，队列初始只包含根节点0
每次从队列中取出一个节点
之后扫面所有与当前节点（0）相邻的节点。因为每条边都被分成若干条边，所以每条边消耗>1步。
**如果一个节点的max_left被更新了（变得更大），将这个节点重新放回队列。（这里类似最短路径的算法）**

最后根据这个最大剩余步数，能够知道可以到达多少节点，比如一个边两个端点的最大步数之和大于这条边分成的边树，那么这条边的所有节点都会被遍历到。
```
class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int M, int N) {
        vector<int> max_left(N, -1);
        vector<vector<pair<int, int>>> outEdge(N);
        for(auto& e:edges) {
            outEdge[e[0]].emplace_back(e[1], e[2]);
            outEdge[e[1]].emplace_back(e[0], e[2]);
        }
        queue<int> q;
        q.emplace(0);
        max_left[0] = M;

        while(q.size()) {
            int current_n = q.front();
            q.pop();
            for(auto& oe:outEdge[current_n]) {
                if(max_left[oe.first] < max_left[current_n] - oe.second-1) {
                    max_left[oe.first] = max_left[current_n] - oe.second-1;
                    q.emplace(oe.first);
                }
            }
        }
        int ans = 0;
        vector<bool> counted(N,false);
        for(auto& e:edges) {
                if(!counted[e[0]]&&max_left[e[0]] > -1) {
                    ans += 1;
                    counted[e[0]] = true;
                }
                if(!counted[e[1]]&&max_left[e[1]] > -1) {
                    ans += 1;
                    counted[e[1]] = true;
                }
                int temp = 0;
                if (max_left[e[0]] > -1)
                    temp += max_left[e[0]];
            if(max_left[e[1]] > -1)
                temp += max_left[e[1]];
            ans += min(temp, e[2]);
        }
        return ans? ans:1;
    }
};
```
需要注意的是，如果根节点不在边的列表中，那么说明只有根节点能被遍历到，这种情况需要处理一下。