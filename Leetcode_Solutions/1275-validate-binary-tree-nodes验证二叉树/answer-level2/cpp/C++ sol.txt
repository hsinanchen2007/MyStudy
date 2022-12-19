### 解题思路

解释如下所示。

### 代码

```cpp
class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) { // 图的问题
        vector<int> indegrees(n, 0); // 计算每个节点的入度
        for (int i = 0; i < n; i++) {
            if (leftChild[i] != -1) indegrees[leftChild[i]]++;
            if (rightChild[i] != -1) indegrees[rightChild[i]]++;
        }

        // 寻找入度为0的节点作为root
        int root = -1;
        for (int i = 0; i < n; i++) {
            if (!indegrees[i]) {
                root = i;
                break;
            }
        }
        if (root == -1) return false; // 没找到入度为0的节点，说明根本没有根，直接返回false，结束

        unordered_set<int> visited({root});
        stack<int> s({root});
        while (!s.empty()) {
            int u = s.top(); s.pop();
            if (leftChild[u] != -1) {
                if (visited.count(leftChild[u])) return false; // 已经被visited过，直接返回false
                visited.insert(leftChild[u]);
                s.push(leftChild[u]);
            }
            if (rightChild[u] != -1) {
                if (visited.count(rightChild[u])) return false; // 已经被visited过，直接返回false
                visited.insert(rightChild[u]);
                s.push(rightChild[u]);
            }
        }

        return visited.size() == n;
    }
};
```