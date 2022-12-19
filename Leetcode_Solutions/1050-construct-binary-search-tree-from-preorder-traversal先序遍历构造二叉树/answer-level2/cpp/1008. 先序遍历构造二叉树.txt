直接按照先序遍历的思维来，逆向恢复即可。  
具体[见此](https://newdee.gitbook.io/leetcode/leetcode-index/1008.construct_binary_search_tree_from_preorder_traversal)

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
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = new TreeNode(preorder[0]);

        stack<TreeNode*> s;
        s.push(root);
        for(int i=1;i<preorder.size();i++)
        {
            TreeNode* cur = s.top();
            if(preorder[i] <cur->val ) 
            {
                cur->left = new TreeNode(preorder[i]);
               s.push(cur->left);


            }
            else
            {
                while( s.size()>1 &&  cur->val < preorder[i])
                {
                s.pop();
                cur = s.top();
                }
                if( cur->val < preorder[i]){
                while(cur->right)
                {
                    s.push(cur->right);
                    cur=cur->right;
                }
                 cur->right = new TreeNode(preorder[i]);
                }
                else{
                    s.push(cur->left);
                    cur=cur->left;
                while(cur->right )
                {
                    s.push(cur->right);
                    cur=cur->right;
                }
                // cout<<cur->val<<endl;
       

                cur->right = new TreeNode(preorder[i]);

                }
                s.push(cur->right);
                  
            }
            
            
        }
        return root;
    }
};
```

> 执行用时 :4 ms, 在所有 C++ 提交中击败了96.01%的用户                                                                                                                                                                                                     
内存消耗 :9 MB, 在所有 C++ 提交中击败了87.58%的用户 