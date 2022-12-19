
前序遍历，递归左子树和递归右子树分别讨论

对于左子树打括号，只要有一侧非空就要打上括号

对于右子树打上括号，只有右子树非空才能打上括号

```
 string res="";
    string tree2str(TreeNode* t) {
        if(t==NULL) return res;
        res.append(to_string(t->val));
        if(t->left||t->right)//只要两侧有一侧非空就要向左子树打上括号
        {
            res.append("(");
            tree2str(t->left);
            res.append(")");
        }
        if(t->right)//对右子树的递归，只有右子树非空才能打上括号。
        {
            res.append("(");
            tree2str(t->right);
            res.append(")");
        }
        return res;
    }
```