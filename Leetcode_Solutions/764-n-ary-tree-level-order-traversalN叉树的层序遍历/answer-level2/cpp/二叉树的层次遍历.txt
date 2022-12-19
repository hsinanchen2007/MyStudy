**思路：
二叉树的层次遍历相同，在处理子节点时，先记录子节点的个数，再通过一个for循环依次将子节点填入队列**
``` C++
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        if(root==NULL)
            return res;
        queue<Node*> q;
        q.push(root);
        while(q.size())
        {
            
            int len=q.size();
            vector<int> temp;
            for(int i=0;i<len;i++)
            {
                root=q.front();
                q.pop();
                temp.push_back(root->val);
                //子节点入队列
                vector<Node*> c=root->children;
                int n_children=c.size();
                for(int j=0;j<n_children;j++)
                {
                    q.push(c[j]);
                }
                    
            }
            res.push_back(temp);
            
        }
        return res;
    }
};

```