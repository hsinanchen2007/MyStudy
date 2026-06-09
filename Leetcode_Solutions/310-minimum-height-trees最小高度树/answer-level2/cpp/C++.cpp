### 解题思路
首先，这题的答案不是1个节点就是2个节点。可以画出只有1~4个节点的图的情况，所以情况的解只有1个或2个。然后4个节点以上的时候，总可以去除掉最外边的节点收敛到1~4个节点的情况。所以该题的答案一定是1个或2个。

第一种超时解法：先求出所有的路径，可以统计出最长的路径长度，然后取出这些最长的路径，取路径中间的节点就是结果了。后面10个左右用例过不了。

第二种解法，从树的叶子节点开始剥，剥到最后只剩1个或2个节点的时候，这两个节点就是所求结果。用这个写法写的时候注意队列的遍历过程。是需要遍历完完整的一次的队列再去判断剩余节点数的。不能把队列空的情况写到外层的循环。

### 代码

```cpp
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) return {0};
        vector<vector<int>> dirTable = vector<vector<int>>(n, vector<int>());
        vector<int> degree = vector<int>(n,0);
        for (auto v : edges) {
            dirTable[v[1]].emplace_back(v[0]);
            dirTable[v[0]].emplace_back(v[1]);
            degree[v[0]]++;
            degree[v[1]]++;
        }
        queue<int> que;
        for (int i=0; i<n; i++) {
            if (degree[i] == 1) {
                que.push(i);
            }
        }
        int count = n;
        while (count > 2) {
            long size = que.size();
            count-=size;
            while (size>0) {
                size--;
                int v = que.front();
                que.pop();
                for (auto u : dirTable[v]) {
                    degree[u]--;
                    if (degree[u] == 1) {
                        que.push(u);
                    }
                }
            }
        }
        
        vector<int> res;
        while (!que.empty()) {
            res.emplace_back(que.front());
            que.pop();
        }
        return res;
    }
};
```