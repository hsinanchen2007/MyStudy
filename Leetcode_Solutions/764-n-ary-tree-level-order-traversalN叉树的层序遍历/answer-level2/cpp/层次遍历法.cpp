### 解题思路

思路与二叉树的层次遍历一致。

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
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ret;
        if(root==NULL) return ret;
        queue<Node*> q;
        q.push(root);
        while(q.size())
        {
            int sz = q.size();
            vector<int> level;
            for(int i=0; i<sz; i++)
            {
                Node* cur = q.front();
                q.pop();
                level.push_back(cur->val);
                for(int j=0; j<cur->children.size(); j++)
                {
                    q.push(cur->children[j]);
                }
            }
            ret.push_back(level);
        }
        return ret;
    }
};
```