![image.png](https://pic.leetcode-cn.com/5ec80ecec242bbd82f493008d24ac18efa09aa43bc35e4094b66851da0b03322-image.png)

bool isSameTree(struct TreeNode* p, struct TreeNode* q)
{
     if(!p&&!q) return true;
     if((!p&&q)||(p&&!q)) return false;
     if(p->val==q->val)
     return isSameTree(p->left,q->left)&&isSameTree(p->right,q->right);
     else
    return false;
}
```
