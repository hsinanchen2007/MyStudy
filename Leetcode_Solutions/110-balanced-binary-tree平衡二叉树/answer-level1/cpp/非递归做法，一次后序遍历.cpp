```cpp []
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct TreeNode2 {
     int val;
     int l;
     int r;
     TreeNode2 *left;
     TreeNode2 *right;
     TreeNode2(int x) : val(x), left(NULL), right(NULL), l(0), r(0) {}
};

void order(TreeNode* root){
    if(root == NULL) return;
    cout<<root->val<<" ";
    order(root->left);
    order(root->right);
}
void order2(TreeNode2* root2){
    if(root2 == NULL) return;
    cout<<root2->val<<" ";
    order2(root2->left);
    order2(root2->right);
}

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;
        TreeNode2* root2 = new TreeNode2(root->val);

        vector<TreeNode2*> s0;
        vector<TreeNode*> s1;
        vector<TreeNode2*> s2;
        s1.push_back(root);
        s0.push_back(root2);
        while(!s1.empty()){
            TreeNode* now = s1.back();
            s1.pop_back();
            TreeNode2* tmp = s0.back();
            s0.pop_back();
            
            s2.push_back(tmp);
            if(now->left != NULL){
                s1.push_back(now->left);
                tmp->left = new TreeNode2(now->left->val);
                s0.push_back(tmp->left);
                
            }
            if(now->right != NULL){
                s1.push_back(now->right);
                tmp->right = new TreeNode2(now->right->val);
                s0.push_back(tmp->right);
            }
        }
        
        while(!s2.empty()){
            TreeNode2 *tmp = s2.back();
            s2.pop_back();
            if(tmp->left == NULL && tmp->right == NULL){
                tmp->l = 0;
                tmp->r = 0;
            }else if(tmp->left == NULL){
                tmp->l = 0;
                tmp->r = max(tmp->right->l, tmp->right->r) + 1;
            }else if(tmp->right == NULL){
                tmp->r = 0;
                tmp->l = max(tmp->left->l, tmp->left->r) + 1;
            }else{
                tmp->l = max(tmp->left->l, tmp->left->r) + 1;
                tmp->r = max(tmp->right->l, tmp->right->r) + 1;
            }
            if(abs(tmp->l - tmp->r) > 1) return false;
        }
        return true;
    }
};
```

定义了一个新的结构，一次后序遍历建树，同时一个栈保留建树时的后序遍历序列，之后遍历一遍该后序遍历序列，更新l和r。
当节点是叶子的时候，l和r都为0.
当节点是非叶子的时候，由于后序遍历，所以必然孩子都已经遇到过了，l直接找左孩子最大的l和r然后+1，r直接找右孩子最大的l和r然后+1，每次更新该节点后判断一次abs(l-r)，如果不满足了就GG，全部满足了就ok。
复杂度O(n)，空间复杂度一共需要三个镜像，但依然是O(n).