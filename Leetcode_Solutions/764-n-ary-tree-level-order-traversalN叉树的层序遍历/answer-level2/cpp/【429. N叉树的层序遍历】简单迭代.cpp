## 思路
### 代码
```c++
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        if (root) {
            queue<Node*> que;
            que.push(root);
            int toDeleted = 1, next = 0;
            vector<int> tmp;
            while (!que.empty()) {
                Node *p = que.front();
                que.pop();
                tmp.push_back(p->val);
                for (auto n : p->children) {
                    if (n) {
                        que.push(n);
                        ++next;
                    }
                }
                --toDeleted;
                if (toDeleted == 0) {
                    res.push_back(tmp);
                    tmp.clear();
                    toDeleted = next;
                    next = 0;
                }
            }
        }
        return res;
    }
};
```
