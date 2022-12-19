
```
如下，在第一步用上 ?: 结构进行判断可大大节约判断nullptr的时间
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2)
    {
       
        if(t1 == nullptr || t2 == nullptr)
        {
            return (t1 == nullptr ? t2 : t1);
        }
        
        else
        {
            t1->val += t2->val;
            t1->left = mergeTrees(t1->left,t2->left);
            t1->right = mergeTrees(t1->right,t2->right);  
            return t1; 
        }  
    
    }
};


```

