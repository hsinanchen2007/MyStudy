### 解题思路
广度优先搜索

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
    struct NodeWithDepth
    {
        Node *node;
        int depth;
    };
    void bfs(Node *root)
    {
        if (!root)
        {
            return;
        }
        NodeWithDepth *a = new NodeWithDepth;
        a->node = root;
        a->depth = 1;
        q.push(a);
        path.push_back(a);
        while (!q.empty())
        {
            NodeWithDepth *item = q.front();
            q.pop();
            int currentDepth = item->depth;
            if (item->node->left)
            {
                NodeWithDepth *child = new NodeWithDepth;
                child->node = item->node->left;
                child->depth = currentDepth+1;
                path.push_back(child);
                q.push(child);
            }
            if (item->node->right)
            {
                NodeWithDepth *child = new NodeWithDepth;
                child->node = item->node->right;
                child->depth = currentDepth+1;
                path.push_back(child);
                q.push(child);
            }
        }
    }
    Node* connect(Node* root) 
    {
        if (!root)
        {
            return NULL;
        }
        bfs(root);
        NodeWithDepth *prev = path[0];
        prev->node->next = NULL;
        NodeWithDepth *current;
        auto iter = path.begin();
        iter++;
        while ( iter != path.end() )
        {
            //串联起来
            current = *iter;
            prev->node->next = NULL;
            current->node->next = NULL;
            if (prev->depth == current->depth)
            {
                //same depth, connect
                prev->node->next = current->node;
            }
            prev = current;
            iter++;
        }
        return path[0]->node;
    }
private:
    queue<NodeWithDepth *> q;
    vector<NodeWithDepth *> path;
};
```