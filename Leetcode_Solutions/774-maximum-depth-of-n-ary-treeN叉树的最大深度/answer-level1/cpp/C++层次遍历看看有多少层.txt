### 解题思路
优点：思路常规，实现快
缺点：耗时长，效率低
### 代码

```cpp
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    //层次遍历求深度
    int maxDepth(Node* root) {
        if(root == NULL) 
            return 0;
        if(root->children.size() == 0) 
            return 1;
        queue<Node*> nodequeue;
        int len;
        nodequeue.push(root);
        int depth = 0;
        Node *node;
        while(!nodequeue.empty())
        {
            len = nodequeue.size();
            if(len != 0) 
                depth++;
            for(int i=0;i<len;i++)
            {
                node = nodequeue.front();
                nodequeue.pop();
                for(int j=0;j<node->children.size();j++)
                {
                    nodequeue.push(node->children[j]);
                }
            }
        }
        return depth;
        
    }
};
```