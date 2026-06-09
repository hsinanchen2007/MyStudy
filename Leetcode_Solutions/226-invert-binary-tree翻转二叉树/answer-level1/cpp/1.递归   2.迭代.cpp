
**方法一：**


```
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        
        if(root==0)return 0;
        auto temp=root->right;
        root->right=invertTree(root->left);
        root->left=invertTree(temp);
        return root;
        
        
    }
};

```

**方法二：**
```
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root==0)return 0;
        auto x=root;
        stack<TreeNode*>s;
        while(x)
        {
            swap(x->right,x->left);
            if(x->right)
            s.push(x->right);
            if(x->left==0)
            {
                if(s.empty())break;
                x=s.top();
                s.pop();       
                continue;
            }
            x=x->left;
            
        }
        return root;
        
    }
};
```




