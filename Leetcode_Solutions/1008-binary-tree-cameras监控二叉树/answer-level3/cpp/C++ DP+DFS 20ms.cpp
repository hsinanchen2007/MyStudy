```
class Solution {
public:
    int minCameraCover(TreeNode* root) {
        if(root==NULL) {
            return 0;
        }
        vector<int> res=dfs(root);
        return min(res[0],res[1]);
    }
    vector<int> dfs(TreeNode* f) { // 0状态是该节点没放监视器，但被监视了；1是放了监视器；2是没放监视器，且没被监视，子节点均被监视；
        vector<int> tmp(3,INT_MAX);  // 这题复杂在状态多些，转移多些。
        if(f->left==NULL&&f->right==NULL) {
            tmp[1]=1;
            tmp[2]=0;
            return tmp;
        }
        vector<int> left;
        vector<int> right;
        if(f->left) {
            left=dfs(f->left);
        }
        if(f->right) {
            right=dfs(f->right);
        }
        int cur_0=INT_MAX,cur_1=INT_MAX,cur_2=INT_MAX;
        if(left.size()==0) {
            cur_0=right[1];
            cur_2=right[0];
            cur_1=min(min(right[0],right[1]),right[2])+1;
        }else if(right.size()==0) {
            cur_0=left[1];
            cur_2=left[0];
            cur_1=min(min(left[0],left[1]),left[2])+1;
        }else if(left.size()>0&&right.size()>0) {
            cur_0=min(left[1]+min(right[0],right[1]), right[1]+min(left[0],left[1]));
            if(left[0]!=INT_MAX&&right[0]!=INT_MAX) {
                cur_2=left[0]+right[0];
            }
            cur_1=min(left[2],min(left[0],left[1]))+min(right[2],min(right[0],right[1]))+1;
        }
        tmp[0]=cur_0;tmp[1]=cur_1;
        tmp[2]=cur_2;
        return tmp;
    }
};
```
