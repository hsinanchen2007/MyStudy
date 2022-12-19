## 思路一：递归
### 代码
```c++
class Solution {
public:
    int maxDepth(Node* root) {
        if (!root) return 0;   
        if (root->children.empty()) return 1;
        int res = 0;        
        for (const auto &child : root->children) {
            int t = 0;      
            t = maxDepth(child);
            res = max(res, t);            
        }             
        return res + 1;
    }
};
```

## 思路二：迭代（层次遍历）
### 代码
```c++
class Solution {
public:
    int maxDepth(Node* root) {
        if (!root) return 0;   
        if (root->children.empty()) return 1;
        int res = 0;        
        queue<Node*> que;
        que.push(root);
        while (!que.empty()) {
            for (auto i = que.size(); i > 0; --i) {
                Node *p = que.front();
                que.pop();
                for (const auto &child : p->children) {
                    if (child) que.push(child);
                }
            }
            ++res;
        }
        return res;
    }
};
```


