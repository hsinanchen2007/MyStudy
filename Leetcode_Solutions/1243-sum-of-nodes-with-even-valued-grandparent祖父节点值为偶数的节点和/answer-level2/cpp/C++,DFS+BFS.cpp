解法一：DFS
```
class Solution {
public:
    int sumEvenGrandparent(TreeNode* root) {
        if(root==NULL)return 0;
        int sum=0;
        if(root->val%2==0){
            if(root->left){
                if(root->left->left)sum=sum+root->left->left->val;
                if(root->left->right)sum=sum+root->left->right->val;
            }
            if(root->right){
                if(root->right->left)sum=sum+root->right->left->val;
                if(root->right->right)sum=sum+root->right->right->val;
            }
        }
        sum+=sumEvenGrandparent(root->left)+sumEvenGrandparent(root->right);
        return sum;
    }
};
```
解法二：BFS
```
class Solution {
public:
    int sumEvenGrandparent(TreeNode* root) {
        queue<TreeNode*>que;
        que.push(root);
        int res=0;
        while(!que.empty()){
            auto v=que.front();
            que.pop();
            bool flag=false;
            if(v->val%2==0){//表明是偶数
                flag=true;
            }
            if(v->left){
                if(v->left->left&&flag){
                    res+=v->left->left->val;
                }
                if(v->left->right&&flag){
                    res+=v->left->right->val;
                }
                que.push(v->left);
            }
            if(v->right){
                if(v->right->left&&flag){
                    res+=v->right->left->val;
                }
                if(v->right->right&&flag){
                    res+=v->right->right->val;
                }
                que.push(v->right);
            }
        }
        return res;
    }
};
```
