### 解题思路
首先，统计入度，可知只能存在一棵二叉树，当入度为0的节点不为1的时候，就代表存在多棵树，此时非二叉树。
然后，使用BFS + vis数组，判断是否存在环。

### 代码

```cpp
class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> inDegree(n);
        for (int i = 0; i < n; i ++) {
            if (leftChild[i] != -1) inDegree[leftChild[i]] ++;
            if (rightChild[i] != -1) inDegree[rightChild[i]] ++;
        }
        
        int root, cnt = 0;
        for (int i = 0; i < inDegree.size(); i ++) {
            if (inDegree[i] == 0) {
                root = i;
                cnt ++;
            }
        }
        if (cnt != 1) return false;
        
        vector<bool> vis(n, false);
        queue<int> q;
        q.push(root);
        while (!q.empty()) {
            int top = q.front(); q.pop();
            if (vis[top]) return false;
                vis[top] = true;
            if (leftChild[top] != -1) 
                q.push(leftChild[top]);
            if (rightChild[top] != -1) 
                q.push(rightChild[top]);
        }
        for (const auto state : vis) 
            if (!state) return false;
        return true;
    }
};
```