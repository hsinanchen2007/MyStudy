**递归**
```
class Solution {
    //从右往左，一个个加
    int sum=0;
    TreeNode* c(TreeNode* root){
        if(root!=NULL){
            c(root->right);
            sum+=root->val;
            root->val=sum;
            c(root->left);            
        }
        return root;
    }
public:
    TreeNode* convertBST(TreeNode* root) {
        return c(root);
    }
};
```
**迭代**
这个还是比较简单的，递归写出来了这个迭代也就能写出来，先右后左 
1.if root==NULL return NULL
2.令cur = root，这点很重要，不然以root继续迭代的话，最后root就指向最左了，函数最后无法返回根节点。
3.int sum = 0;用于存放累加值。
4.如果栈不为空或者cur不为空，沿cur向右走到底，并将途径节点压栈；
  弹出栈顶节点s，sum += s->val，并用sum更新s->val的值；
  判断s是否有左节点，有的话，将cur更新为s->left，继续迭代。
```
class Solution {

public:
    TreeNode* convertBST(TreeNode* root) {
        if(root==NULL) return NULL;
        stack<TreeNode*>s;
        TreeNode* cur=root;
        int sum=0;
        while(!s.empty()||cur!=NULL){
            while(cur){
                s.push(cur);
                cur=cur->right;
            }
            TreeNode* t =s.top();
            sum+=t->val;
            t->val=sum;
            s.pop();
            if(t->left) cur=t->left;
        }
        return root;
    }
};
```

