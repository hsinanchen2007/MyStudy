二叉搜索树的中序遍历是从小到大的，迭代法中序遍历，记录下拐点，**注意**拐点可能有两个，也可能只有一个。

    2和5交换
          5                     
         / \   4
        /   \ / \
       /     3   \
      /           2
     1
    2和3交换
               5
              /
             4
        3   / 
       / \ /      
      /   2       
     1

```c++
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
    void recoverTree(TreeNode* root) {
        TreeNode *first, *second, *tmp = new TreeNode(INT_MIN);
        stack<TreeNode*> s;
        int flag = 1;
        while(root || !s.empty()){
            while(root){
                s.push(root);
                root = root->left;
            }
            root = s.top();
            s.pop();
            if(tmp->val > root->val){
                if(flag--) first = tmp;
                second = root;
            }
            tmp = root;
            root = root->right;
        }
        exchange(first, second);
    }
    void exchange(TreeNode* first, TreeNode* second){
        int tmp = first->val;
        first->val = second->val;
        second->val = tmp;
    }
};
```

