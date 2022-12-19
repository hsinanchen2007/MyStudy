递归
```
    bool isSymmetric(TreeNode*A,TreeNode*B){
        if(A==NULL&&B==NULL)
            return true;
        if(A==NULL||B==NULL)
            return false;
        return A->val==B->val&&isSymmetric(A->left,B->right)&&isSymmetric(A->right,B->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL)
            return true;
        return isSymmetric(root->left,root->right);
    }
```
迭代：
想问题不要总是想的太复杂，递归问题总是依赖于遍历来解决，迭代问题同样也是遍历，只要熟练掌握迭代方法的那几种遍历，迭代也同样是信手拈来。
迭代1：queue的层次遍历
```
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root==NULL)
            return true;
        queue<TreeNode*> qleft,qright;
        qleft.push(root->left);
        qright.push(root->right);
        while(!qleft.empty()){
            TreeNode* left = qleft.front();
            qleft.pop();
            TreeNode* right = qright.front();
            qright.pop();
            if(left==NULL&&right!=NULL||left!=NULL&&right==NULL||left!=NULL&&right!=NULL&&left->val!=right->val)
                return false;
            if(left){
                qleft.push(left->left);
                qleft.push(left->right);
                qright.push(right->right);
                qright.push(right->left);
            }
        }
        if(qright.empty()==false)
            return false;
        return true;
    }
};
```
迭代2：stack的遍历
```
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root==NULL)
            return true;
        stack<TreeNode* > sleft,sright;
        sleft.push(root->left);
        sright.push(root->right);
        while(!sleft.empty()){
            TreeNode* left = sleft.top();
            TreeNode* right = sright.top();
            sleft.pop();
            sright.pop();
            if(left==NULL&&right||right==NULL&&left||left&&right&&left->val!=right->val)
                return false;
            if(left){
                sleft.push(left->left);
                sleft.push(left->right);
                sright.push(right->right);
                sright.push(right->left);
            }
        }
        if(!sright.empty())
            return false;
        return true;
    }
};
```