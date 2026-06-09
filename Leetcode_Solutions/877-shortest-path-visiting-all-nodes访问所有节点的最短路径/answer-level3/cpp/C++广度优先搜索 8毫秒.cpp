### 解题思路
![image.png](https://pic.leetcode-cn.com/d56fd14770202fda24ab0f029e5f323b98daed124cbb566049ed9463e6b2b397-image.png)

使用广度优先搜索算法，创建一个结构体node，保持当前几点的信息，包括当前节点、当当前节点时已经访问的步数、已经访问的节点集合(用一个bit位表示一个节点)；同时为了防止重复遍历，用一个二维数组path记录遍历的路径，数组的第一维表示已经访问的节点集合，数组的第二维表示当前待访问的节点。
1、所有节点都以node的方式入栈
2、对node进行遍历，遍历到某个节点的已访问节的集合为目标值是退出
3、在遍历过程中，如果某条路径已经访问过(path[][]为true)，此节点不入栈

### 代码

```cpp
using namespace std;
struct node {
    int current;
    int step;
    int cover;
    node(int _curr, int _step, int _cover) : current(_curr), step(_step), cover(_cover) {}
};
class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph)
    {
        queue<node> nodeQ = {};
        int size = graph.size();
        bool path[1<<size][size]; // 数组的第一维表示已经访问的节点集合，数组的第二维表示当前待访问的节点

        for (int i = 0; i < size; ++i) {
            nodeQ.push(node(i, 0, 1 << i));
        }
        memset(path, false, sizeof(path));

        while (!nodeQ.empty()) {
            int nodeNum = nodeQ.size();
            while (nodeNum--) {
                node oneNode = nodeQ.front();
                nodeQ.pop();

                if(oneNode.cover == (1 << size) -1 ) {
                    return oneNode.step;
                }

                for (const auto& at : graph[oneNode.current]) {
                    if (path[oneNode.cover | 1 << at][at]) {
                        continue;
                    }
                    path[oneNode.cover | 1 << at][at] = true;
                    nodeQ.push(node(at, oneNode.step + 1, oneNode.cover | 1 << at));
                }
            }
        }
        return 0;
    }
};
```