### 递归

ps:第一次调用递归函数时，return的那段代码的意思是，判断根节点的左子树与右子树的值是否相等，以及让左子树的左子树与右子树的右子树作参数执行一次函数，再让左子树的右子树和右子树的左子树作参数执行一次函数，递归下去即可判断是否为对称（表达有点混乱，但是画一下图就很好理解了）

```cpp
class Solution {
public:
    bool isSymmetric(TreeNode* root) 
    {
        if(root == NULL)    return true;
        return isMirror(root->left,root->right);
    }
    
    bool isMirror(TreeNode *p,TreeNode *q)          //递归函数
    {
        if(!p && !q)        return true;        //如果p,q均为NULL
        if(!p || !q)        return false;       //p,q只有一者为NULL

        return (p->val==q->val) && isMirror(p->left,q->right) && isMirror(p->right,q->left);        
    }
};
```



### 使用队列

```cpp
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root==NULL)          return true;
        queue<TreeNode*> q;         
        q.push(root->left);
        q.push(root->right);

        while(!q.empty()) {
            TreeNode* t1 = q.front();       q.pop();
            TreeNode* t2 = q.front();       q.pop();
            if(!t1 && !t2)      continue;
            if(!t1 || !t2)      return false;

            if(t1->val != t2->val)          return false;
            q.push(t1->left);
            q.push(t2->right);
            q.push(t1->right);
            q.push(t2->left);        //入队顺序与递归每轮判断的顺序相同，画图便于理解     
        }
        return true;
    }
};
```
### 使用栈（与队列大同小异）

```cpp
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root==NULL)          return true;
        stack<TreeNode*> q;         
        q.push(root->left);
        q.push(root->right);

        while(!q.empty()) {
            TreeNode* t1 = q.top();       q.pop();
            TreeNode* t2 = q.top();       q.pop();
            if(!t1 && !t2)      continue;
            if(!t1 || !t2)      return false;

            if(t1->val != t2->val)          return false;
            q.push(t1->left);
            q.push(t2->right);
            q.push(t1->right);
            q.push(t2->left);               
        }
        return true;
    }
};
```