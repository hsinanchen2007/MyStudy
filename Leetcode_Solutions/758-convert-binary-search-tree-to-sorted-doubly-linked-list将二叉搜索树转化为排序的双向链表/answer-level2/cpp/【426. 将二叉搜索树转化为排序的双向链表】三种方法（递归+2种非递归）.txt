## 思路一：非递归
先一直向左走，利用栈保存经过节点，直到左节点为空，从栈中弹出节点进行访问，然后然后再设置节点为当前节点的右节点。
## 代码
```c++
class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if (!root) {
            return root; 
        }
        stack<Node *> st;        
        Node *head = nullptr;
        Node *pre = nullptr;        
        while (root || !st.empty()) {
            //1. 一直向左走，直到遇到左节点为空
            while (root) {
                st.push(root);
                root = root->left;
            }
            //2. 访问当前节点
            root = st.top();
            st.pop();
            if (!pre) {
                head = root;                
            } else {
                pre->right = root;
                root->left = pre;                                
            }            
            pre = root;
            //3. 再访问右子树
            root = root->right;
        }
        pre->right = head;
        head->left = pre;
        return head;
    }
};
```

## 思路二：简化代码（新增一个头节点）
## 代码
```c++
class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if (!root) {
            return root; 
        }
        stack<Node *> st;     
        //新增头节点
        Node *pre = new Node(0, nullptr, nullptr);
        Node *head = pre;      
        while (root || !st.empty()) {
            while (root) {
                st.push(root);
                root = root->left;
            }
            root = st.top();
            st.pop();
            pre->right = root;
            root->left = pre;                                                        
            pre = root;
            root = root->right;
        }
        pre->right = head->right;
        head->right->left = pre;
        return head->right;
    }
};
```


## 思路三：递归
## 代码
```c++
class Solution {
    Node *pre = nullptr;
    Node *head = nullptr;
public:
    Node* treeToDoublyList(Node* root) {
        if (!root) {
            return root; 
        }
        //将树中间节点转换为双向链表
        helper(root);
        //转换头尾节点指针
        pre->right = head;
        head->left = pre;
        return head;
    }
    void helper(Node *root) {
        if (root) {
            helper(root->left);
            if (!pre) {
                head = root;                
            } else {
                pre->right = root;
                root->left = pre;
            }
            pre = root;
            helper(root->right);
        }
    }
};
```
