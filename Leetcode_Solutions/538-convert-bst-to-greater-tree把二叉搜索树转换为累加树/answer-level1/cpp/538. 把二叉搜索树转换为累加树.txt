具体分析[见此处](https://newdee.gitbook.io/leetcode/leetcode-index/538.convert_bst_to_greater_tree)
中序遍历：

```
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    stack<TreeNode*> all;
    void traversal(TreeNode* root)
    {
        if(!root) return;
        if(root->left) traversal(root->left);
        all.push(root);
        if(root->right) traversal(root->right);
    }
public:
    TreeNode* convertBST(TreeNode* root) {
        if(!root) return 0;
         traversal(root);
        int s=0;
       //cout<<all.size()<<endl;
        while(!all.empty())
        {
             s+=all.top()->val;
        //  cout<<s<<endl;
           all.top()->val=s;
            all.pop();
        }
        
            
        return root;
    }
};
```

> 执行用时 : 56 ms, 在Convert BST to Greater Tree的C++提交中击败了91.81% 的用户  
内存消耗 : 24.2 MB, 在Convert BST to Greater Tree的C++提交中击败了79.10% 的用户