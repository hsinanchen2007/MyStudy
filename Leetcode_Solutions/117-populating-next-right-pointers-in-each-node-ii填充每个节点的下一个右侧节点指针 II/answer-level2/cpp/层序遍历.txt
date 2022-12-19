```
class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL)
            return NULL;
        //
        queue<Node*> q;
        q.push(root);
        Node* tmp;
        while(!q.empty())
        {
            int size = q.size();
            while(size--)
            {
                tmp = q.front();
                q.pop();
                if(size>0)
                {
                    tmp->next = q.front();
                }else
                {
                    tmp->next = NULL;
                }
                //
                if(tmp->left) q.push(tmp->left);
                if(tmp->right) q.push(tmp->right);
            }
        }
        return root;
    }
};
```