## 思路一：层次遍历
### 代码
```c++
class Solution {
public:
    Node* connect(Node* root) {
        if (root != nullptr) {
            queue<Node*> que;
            int next = 0, toDeleted = 1;
            que.push(root);
            while (!que.empty()) {
                Node *p = que.front();
                if (p->left) {
                    que.push(p->left);
                    ++next;
                }
                if (p->right) {
                    que.push(p->right);
                    ++next;
                }
                --toDeleted;
                que.pop();
                if (toDeleted == 0) {
                    p->next = nullptr;
                    toDeleted = next;
                    next = 0;                    
                } else {
                    p->next = que.front(); 
                }
            }
        }
        return root;
    }
};
```
### 另一种写法
```c++
class Solution {
public:
    Node* connect(Node* root) {
        if (root) {
            queue<Node*> que;
            que.push(root);
            while (!que.empty()) {
                int size = que.size();//当前层大小
                for (int i = 0; i < size; ++i) {//遍历当前层
                    Node *p = que.front();
                    que.pop();
                    if (i < size - 1) {//最后一个元素next为空
                        p->next = que.front();
                    }
                    if (p->left) que.push(p->left);
                    if (p->right) que.push(p->right);
                }
            }
        }        
        return root;
    }
};
```

## 思路二：递归（击败99.94%）
### 代码
```c++
class Solution {
public:
    Node* connect(Node* root) {
        if (root != nullptr) {
            if (root->left) {
                root->left->next = root->right;
            }
            if (root->right) {
                root->right->next = root->next ? root->next->left : nullptr;
            }
            root->left = connect(root->left);
            root->right = connect(root->right);
        }
        return root;
    }
};
```

