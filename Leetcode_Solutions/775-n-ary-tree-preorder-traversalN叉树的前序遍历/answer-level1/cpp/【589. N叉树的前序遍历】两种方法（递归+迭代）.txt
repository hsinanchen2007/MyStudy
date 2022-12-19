## 思路一：递归
### 代码
```c++
class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> res;
        if (root) {        
            helper(root, res);
        }
        return res;
    }

    void helper(Node *root, vector<int> &res) {
        if (root) {
            res.push_back(root->val);
            for (auto child : root->children) {
                helper(child, res);
            }            
        }
    }
};
```

## 思路二：迭代
### 代码
```c++
class Solution {
public:
    vector<int> preorder(Node* root) {
        if (!root) return {};
        vector<int> res;
        stack<Node*> st;
        st.push(root);
        while (!st.empty()) {
            Node *p = st.top();
            st.pop();
            res.push_back(p->val);            
            for (auto it = p->children.crbegin(); it != p->children.crend(); ++it) {
                st.push(*it);
            }
        }
        return res;
    }
};
```

