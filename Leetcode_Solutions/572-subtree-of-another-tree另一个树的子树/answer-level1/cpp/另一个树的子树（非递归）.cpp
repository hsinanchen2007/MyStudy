### 解题思路
主要函数里找相同的开头进行匹配，辅助函数判断匹配是否为相同的树。

### 代码

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool f=false;  //定义一个标记，只要有一个为true，就是true
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(s==nullptr||t==nullptr) return false;
        stack<TreeNode*>res;
        TreeNode* tmp;
        while(s||res.size()){
            while(s){
                if(s->val==t->val)  f=f||isSameTree(s,t); //注意：这一块一个树里可能有许多相同的节点。。
                res.push(s);
                s=s->left;
            }
            tmp=res.top();
            res.pop();
            s=tmp->right; //左右找
        }
        return f;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL&&q==NULL) return true;
        if(p==NULL||q==NULL) return false;
        if(p->val!=q->val) return false;
        return isSameTree(p->right,q->right)&&isSameTree(p->left,q->left);
    }
};
```