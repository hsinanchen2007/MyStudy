### 解题思路
本题不可采取深度优先，因为可能存在某些子节点为空，需要next连接到尚未完成的父节点的后续节点。采取广度优先可以轻松解决，每次遍历该层，然后再去处理下一层。
执行用时:12 ms, 在所有 C++ 提交中击败了95.76% 的用户
内存消耗:19 MB, 在所有 C++ 提交中击败了100.00%的用户

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
    Node* connect(Node* root) 
    {
        Node *headParent = root;
        while (headParent != NULL)
        {
            // 获得队首节点的父节点
            while (headParent && headParent->left == NULL && headParent->right == NULL)
                headParent = headParent->next;

            if (headParent == NULL)
                break;

            Node *cur = NULL, *tmp = headParent;

            // 广度优先遍历该层
            while (tmp)
            {
                if (tmp -> left)
                {
                    if (cur != NULL)
                    {
                        cur->next = tmp->left;
                    }
                    cur = tmp->left;
                }
                if (tmp -> right)
                {
                    if (cur != NULL)
                    {
                        cur->next = tmp->right;
                    }
                    cur = tmp->right;
                }
                tmp = tmp->next;
            }         

            // 进入下一级
            headParent = headParent->left ? headParent->left : headParent->right;
        }
        return root;
    }
};
```