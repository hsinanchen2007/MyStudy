方法一：
思路：递归判断，结点左子树，右子树均为搜索树，
且左子树所有结点 < 根节点 < 右子树所有结点
1、注意容易犯如下错误：只验证了左节点 < 根节点 < 右结点，
并未保证左子树所有结点 < 根节点 < 右子树所有结点
2、修改：根节点与左子树的最大结点，右子树的最小结点比较
```
class Solution {
public:
    TreeNode* max(TreeNode* root)  //寻找搜索树最大节点
    {
        if(!root) return nullptr;
        TreeNode* p = root;
        while(p->right)
            p = p->right;
        return p;
    }
    TreeNode* min(TreeNode* root)//寻找搜索树最小节点
    {
        if(!root) return nullptr;
        TreeNode* p = root;
        while(p->left)
            p = p->left;
        return p;
    }
    bool isValidBST(TreeNode* root) {
        if(!root)
            return true;
        else if(root->left && root->right)  //左子树、右子树非空，根节点大于左子树的最大结点，小于右子树的最小结点，则为搜索树
            return (root->val > max(root->left)->val)  && 
                    (root->val < min(root->right)->val) &&
                    isValidBST(root->left) &&
                    isValidBST(root->right);
        else if(!(root->left) && root->right)
            return (root->val < min(root->right)->val) && 
                    isValidBST(root->right);
        else if(root->left && !(root->right))
            return (max(root->left)->val < root->val) &&
                    isValidBST(root->left);
        else
            return true;  
    }
};
```
方法二：中序遍历
二叉搜索树，中序遍历得从小到大得顺序序列，所以通过中序遍历，
每个节点大于它前面得结点，即是搜索二叉树
```
bool isValidBST(TreeNode* root) {
        if(!root)
            return true;
        TreeNode* pre = nullptr;
        TreeNode* p = root;
        stack<TreeNode*> s;
        while(p || !s.empty())
        {
            while(p)
            {
                s.push(p);
                p = p->left;
            }
            if(!s.empty())
            {
                p = s.top(); s.pop();
                if(pre!=nullptr && pre->val >= p->val)
                    return false;
                pre = p; 
                p = p->right;
            }
        }
        return true;
    }
```
