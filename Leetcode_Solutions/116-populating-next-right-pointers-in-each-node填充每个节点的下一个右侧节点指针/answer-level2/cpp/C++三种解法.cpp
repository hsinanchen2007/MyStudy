

```cpp
class Solution {
public:
    Node* connect(Node* root) { // 递归解法
        if (root == NULL)
            return NULL;

        if (root->left)
            root->left->next = root->right;
        if (root->right)
            root->right->next = (root->next ? root->next->left : NULL);

        connect(root->left);
        connect(root->right);
    }

    Node* connect_1(Node* root) {   // 采用层级遍历的方法，符合题目要求
        if (root == NULL)
            return NULL;

        Node* cur;
        Node* levelRoot = root; // 每一层的头结点

        while(levelRoot) {            
            cur = levelRoot;
            while (cur && cur->left) {     // 说明有子结点，left 和 right 子结点都存在，开始层级遍历
                cur->left->next = cur->right;
                if (cur->next == NULL) {
                    cur->right->next = NULL;
                }
                else {
                    cur->right->next = cur->next->left;
                }
                cur = cur->next;
            }
            
            levelRoot = levelRoot->left;
        }
        return root;
    }

    Node* connect_2(Node* root) {   // 此解法虽然可以得到结果，但不符合题意使用O(1)的空间
        if (root == NULL)
            return NULL;

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* tmp = q.front();
            q.pop();

            if (tmp->left) {    // 说明有子结点，left 和 right 子结点都存在
                tmp->left->next = tmp->right;
                q.push(tmp->left);

                if (tmp->next) {
                    tmp->right->next = q.front()->left;
                    q.push(tmp->right);
                }
                else {
                    tmp->right->next = NULL;
                    q.push(tmp->right);
                }
            }            
        }
        return root;        
    }
};
```
