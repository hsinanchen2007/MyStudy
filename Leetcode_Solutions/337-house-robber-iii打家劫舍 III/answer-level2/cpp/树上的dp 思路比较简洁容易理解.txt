//这个感觉比较好理解 树上的dp
class Solution {
public:
    int res = 0;
    vector<int> dfs(TreeNode* root){
        if(!root){
            return vector<int>{0,0}; //第一个是包括根节点的最大值 第二个是不包括根节点的最大值
        }
        vector<int> l = dfs(root->left);
        vector<int> r = dfs(root->right);
        int m1 = max(l[0],l[1]), m2 = max(r[0],r[1]), m3 = m1+m2;
        vector<int> tmp{root->val+l[1]+r[1],m3}; //更新当前根节点的（包含不包含）的最大值
        res = max(res,max(tmp[0],tmp[1])); 
        return tmp;
    }
    int rob(TreeNode* root) {
        dfs(root);
        return res;
    }
};