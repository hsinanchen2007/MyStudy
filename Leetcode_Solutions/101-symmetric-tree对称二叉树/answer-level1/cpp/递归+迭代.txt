```
class Solution {
public:
    // 方法二 迭代 队列
    // bool isSymmetric(TreeNode* root) {
    //     TreeNode* lf;
    //     TreeNode* rt;
    //     queue<TreeNode*> que;
    //     que.push(root);
    //     que.push(root);
    //     while(!que.empty()){
    //         lf=que.front();
    //         que.pop();
    //         rt=que.front();
    //         que.pop();
    //         if(lf==NULL&&rt==NULL) continue;
    //         if(lf==NULL||rt==NULL) return false;
    //         if(lf->val!=rt->val) return false;
    //         que.push(lf->left);
    //         que.push(rt->right);
    //         que.push(rt->right);
    //         que.push(lf->left);
    //     }
    //     return true;
    // }

    bool isSymmetric(TreeNode* root) {
        TreeNode* lf;
        TreeNode* rt;
        queue<pair<TreeNode*,TreeNode*>> que;
        que.push(pair(root,root));
        while(!que.empty()){
            lf=que.front().first;
            rt=que.front().second;
            que.pop();
            if(lf==NULL&&rt==NULL) continue;
            if(lf==NULL||rt==NULL) return false;
            if(lf->val!=rt->val) return false;
            que.push(pair(lf->left,rt->right));
            que.push(pair(lf->right,rt->left));
        }
        return true;
    }

    // 方法一、递归
    // bool isSymmetric(TreeNode* root) {
    //     return ismirror(root,root);
    // }
    // bool ismirror(TreeNode* lf,TreeNode* rt){
    //     if(lf==NULL&&rt==NULL) return true;
    //     if(lf==NULL||rt==NULL) return false;
    //     if(lf->val==rt->val&&ismirror(lf->left,rt->right)&&ismirror(lf->right,rt->left)) return true; 
    //     return false;
    // }

    // bool isSymmetric(TreeNode* root) {
    //     stack<TreeNode*> sk;
    //     TreeNode* lt=root;
    //     TreeNode* rt;
    //     while(rt){
    //         while(lt){
    //             sk.emplay_back(lt->right);
    //             lt=lt->left;
    //         }
    //         if(sk.top()!==NULL) return false;

    //     }
        
    // }
};
```
