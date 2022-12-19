层次遍历迭代
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
    int maxDepth(Node* root) {
        if(root==NULL)
            return 0;
        int res=0;
        queue<Node*> q;
        q.push(root);
        while(q.size())
        {
            int len=q.size();
            res++;
            for(int i=0;i<len;i++)
            {
                root=q.front();
                q.pop();                
                vector<Node*> c=root->children;                
                for(int j=0;j<c.size();j++)
                {
                    q.push(c[j]);
                }                    
            }
        }
        return res;
    }
};
```