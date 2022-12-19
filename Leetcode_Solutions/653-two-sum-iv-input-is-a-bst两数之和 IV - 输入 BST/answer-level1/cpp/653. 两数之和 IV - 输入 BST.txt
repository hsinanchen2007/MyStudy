具体[见此](https://newdee.gitbook.io/leetcode/leetcode-index/653.two_sum_iv_input_is_a_bst)  

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
 vector<int> target;
    void initial(TreeNode* root)
    {
        if(!root) return;
        if(root->left)    initial(root->left);
            target.push_back(root->val);
        if(root->right) initial(root->right);
        
        
    }
    
public:
    bool findTarget(TreeNode* root, int k) {
       
        initial(root);
        int first=0;
        int last=target.size()-1;
        while(first<last)
        {
            int t=target[first]+target[last];
            if(t==k) return true;
            else if(t>k) last--;
            else first++;
        }
        return false;
    }
};
```

>  执行用时 : 76 ms, 在Two Sum IV - Input is a BST的C++提交中击败了60.15% 的用户  
内存消耗 : 25 MB, 在Two Sum IV - Input is a BST的C++提交中击败了83.87% 的用户