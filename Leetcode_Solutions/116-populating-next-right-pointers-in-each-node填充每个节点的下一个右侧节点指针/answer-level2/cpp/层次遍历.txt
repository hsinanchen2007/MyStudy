### 解题思路
此处撰写解题思路

### 代码

```cpp
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL) return NULL;
        deque<Node*> queue;
        queue.push_back(root);

        int level = 1;
        while(!queue.empty())
        {
            level = queue.size();
            for(int i = 0; i < level; ++i)
            {
                Node* temp = queue.front();
                queue.pop_front();
                if(i+1 < level)
                    temp->next = queue.front();
                else
                    temp->next = NULL;

                if(temp->left != NULL)  queue.push_back(temp->left);
                if(temp->right != NULL) queue.push_back(temp->right);
            }
        }
        return root;
    }
};
```