### 解题思路
1. 与#145题类似
2. 换上这一句  `for(int i=0;i<p->children.size());++i)   s1.push(p->children[i]);`

### 代码
```
class Solution 
{
public:
    vector<int> postorder(Node* root) 
    {
        vector<int> res;
        if(root==NULL) return res;

        stack<Node*> s1;
        stack<Node*> s2;
        Node* p=root;
        s1.push(p);

        while(!s1.empty())
        {
            p=s1.top();
            s1.pop();
            s2.push(p);
            int len=p->children.size();
            for(int i=0;i<len;++i)
                s1.push(p->children[i]);
        }

        while(!s2.empty())
        {
            p=s2.top();
            s2.pop();
            res.push_back(p->val);
        }
        return res;
    }
};
```