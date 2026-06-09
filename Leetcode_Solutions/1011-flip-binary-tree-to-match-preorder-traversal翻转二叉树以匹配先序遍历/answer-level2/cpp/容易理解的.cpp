 比较了官方的解法，发现不是很容易理解。我的解法是先构造一个前序字典，然后每次通过左右子树划分 voyage，再分别遍历。
递归函数返回的是子树是否能翻转得到结果。
```c++
class Solution {
public:
    bool can(TreeNode* root, int left, int right, vector<int>& voyage, unordered_map<int, int>& pre_order, vector<int>& result) {
        if(root->val != voyage[left]) return false; //根节点值和当前序列首位不同，直接返回 false
        if(root->left == nullptr && root->right == nullptr) {
            return left == right;
        }
        if(root->left == nullptr) {
            return can(root->right, left+1, right, voyage, pre_order, result);
        }
        if(root->right == nullptr) {
            return can(root->left, left+1, right, voyage, pre_order, result);
        }
        int left_index = pre_order[root->left->val]; 
        int right_index = pre_order[root->right->val]; //左右子树的下标。
        if(left_index > right_index) { //左比右大，需要翻转
            TreeNode* tmp = root->left;
            root->left = root->right;
            root->right = tmp;
            swap(left_index, right_index); //左右下标对换一下
            result.push_back(root->val);
        }

        return can(root->left, left_index, right_index - 1, voyage, pre_order, result) && 
            can(root->right, right_index, right, voyage, pre_order, result);
    }

    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        unordered_map<int, int> pre_order;
        for(int i=0;i<voyage.size();++i){
            pre_order[voyage[i]] = i;
        }
        vector<int> result;
        if(can(root, 0, voyage.size()-1, voyage, pre_order, result)) {
            return result;
        } else {
            return {-1};
        }

    }
};
```