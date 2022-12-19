### 解题思路

前序遍历模板
```
void preorder(Node* root) 
{
    stack<Node*> myStack;
    Node* p;

    if(root==NULL)return;

    myStack.push(root);

    while(!myStack.empty())
    {
        p=myStack.top();
        myStack.pop();

        visit(p);     ////处理

        if(p->right!=NULL){myStack.push(p->right);}
        if(p->left!=NULL){myStack.push(p->left);} 
        
    }

```

根据题意变化
```
int width=p->children.size();
for(int i=width-1;i>=0;--i)
{
    myStack.push(p->children[i]);
}
```




### 代码

```cpp

class Solution 
{
public:
    vector<int> preorder(Node* root) 
    {
        vector<int> res;
        stack<Node*> myStack;
        Node* p;

        if(root==NULL)return res;

        myStack.push(root);

        while(!myStack.empty())
        {
            p=myStack.top();
            myStack.pop();
            res.push_back(p->val);
            int width=p->children.size();

            for(int i=width-1;i>=0;--i)
            {
                myStack.push(p->children[i]);
            }
        }
        return res;
    }
};


















```