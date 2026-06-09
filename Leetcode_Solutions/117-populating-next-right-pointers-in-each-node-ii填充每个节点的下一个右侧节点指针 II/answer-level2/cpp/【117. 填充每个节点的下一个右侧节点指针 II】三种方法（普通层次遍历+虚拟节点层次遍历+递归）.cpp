## 思路一：层次遍历
### 代码
```c++
class Solution {
public:
    Node* connect(Node* root) {
        if (root) {
            queue<Node*> que;
            int next = 0, cur = 1;
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
                que.pop();
                --cur;
                if (cur == 0) {
                    p->next = nullptr;
                    cur = next;
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
                int size = que.size();
                for (int i = 0; i < size; ++i) {
                    Node *p = que.front();
                    que.pop();
                    if (i < size - 1) {
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

## 思路二：不使用queue层次遍历
设置一个虚拟节点，使其next指针指向每层第一个节点。
### 代码
常量级额外空间
```c++
class Solution {
public:
    Node* connect(Node* root) {
        Node *dummy = new Node(0, nullptr, nullptr, nullptr), *cur = dummy, *head = root;
        while (root) {
            if (root->left) {
                cur->next = root->left;
                cur = cur->next;
            }
            if (root->right) {
                cur->next = root->right;
                cur = cur->next;
            }
            root = root->next;
            if (!root) {
                cur = dummy;
                root = dummy->next;
                dummy->next = nullptr;
            }
        }        
        return head;
    }
};
```

## 思路三：递归
### 代码
```c++
class Solution {
public:
    Node* connect(Node* root) {        
        helper(root);
        return root;
    }

    void helper(Node *root) {
        if (root) {
            Node *dummy = new Node(0, nullptr, nullptr, nullptr), *cur = root, *pre = dummy;
            while (cur) {
                if (cur->left) {
                    pre->next = cur->left;
                    pre = pre->next;
                }
                if (cur->right) {
                    pre->next = cur->right;
                    pre = pre->next;
                }
                cur = cur->next;
            }
            helper(dummy->next);
        }        
    }
};
```


