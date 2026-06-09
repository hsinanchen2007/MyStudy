```
class Solution {
public:
    void recoverTree(TreeNode* root) {
        //找第一个大于后继和最后一个小于前驱的节点，交换它们的val
        TreeNode* first=nullptr,*last=nullptr,*prev=nullptr;
        while(root){
            auto tmp=root->left;
            while(tmp && (tmp->right!=nullptr && tmp->right!=root))tmp=tmp->right;
            if(tmp==nullptr || tmp->right==root){
                if(tmp)tmp->right=nullptr;
                if(prev && root->val < prev->val) {
						last = root;
						first = first == nullptr ? prev : first;
                }
                prev=root;
                root=root->right;
            }else{
                tmp->right=root;
                root=root->left;
            }
        }
        if(first&&last)std::swap(first->val,last->val);
    }
};
```
