### 解题思路
此处撰写解题思路

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
    vector<vector<int>> res;
    vector<int> v;
    queue<Node*> que;
    vector<vector<int>> levelOrder(Node* root) {
        if(!root)
            return res;
        que.push(root);
        Node* end = root;
        while(!que.empty())
        {
            Node* curNode = que.front();
            for(int i = 0; i < curNode->children.size(); i++)
                if(curNode->children[i])
                    que.push(curNode->children[i]);
            que.pop();
            v.push_back(curNode->val);
            if(curNode == end)
            {
                res.push_back(v);
                end = que.back();
                v.clear();
            }
        }
        return res;
    }
};
```