### 解题思路
时间0ms；内存9.6MB；
迭代采用栈。基本思路同前序中序基本类似，但后序与前两者不同的地方在于遍历完左子树后，不能直接把根结点直接退栈，需要将右子树也便利结束后才可以退出根节点。引入一个辅助指针q（来指示刚刚便利结束的节点），分两种情况讨论（1）无右子树（2）右子树已经便利过，那么就可以退出根节点并访问；否则将p置为节点的右孩子，进行循环入栈，以此类推。

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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> B;
        TreeNode *p=root,*q=NULL;
        stack<TreeNode*> stk;
        while(!stk.empty()||p){
            if(p){
                stk.push(p);
                p=p->left;
            }else{
                p=stk.top();
                p=p->right;
                if(p==NULL||p==q){
                    q=stk.top();
                    stk.pop();
                    B.push_back(q->val);
                    p=NULL;
                }
            }
        } 
        return B;
    }
};
```