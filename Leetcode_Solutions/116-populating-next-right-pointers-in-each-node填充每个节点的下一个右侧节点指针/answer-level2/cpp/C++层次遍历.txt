```
class Solution {
public:
    void BFS(Node* root)
    {
        queue<Node*> que;
        que.push(root);
        while(!que.empty())
        {
            int len=que.size();
            for(int i=0;i<len-1;i++)
            {
               
                Node*q=que.front();
                que.pop();
                //  cout<<q->val<<endl;
                q->next=que.front();
                if(q->left!=NULL){
                que.push(q->left);
                que.push(q->right);
                }
            }
            Node*q=que.front();
            que.pop();
            q->next=NULL;
            if(q->left!=NULL)
            {
             que.push(q->left);
             que.push(q->right);
            }


        }
    }
    Node* connect(Node* root) {
        if(root==NULL)return root;
        BFS(root);
        return root;
    }
};
```
