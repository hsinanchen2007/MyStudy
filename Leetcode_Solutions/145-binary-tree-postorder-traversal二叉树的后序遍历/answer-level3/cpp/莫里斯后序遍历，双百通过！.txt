### 解题思路
核心是利用叶子结点中的空指针来存储后继或者前驱的线索信息。
推荐大家先去了解莫里斯前序遍历和莫里斯中序遍历。
然后，后序遍历其实就是翻转的前序遍历，
前序遍历，先自己，再左，最后右；
后序遍历，先左，再右，最后自己，
（翻转一下）->
         先自己，再右，最后左。
 

### 代码

```cpp
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        TreeNode* current=root;
        TreeNode* succeed=NULL;

        while(current!=NULL){
            if(current->right==NULL){
                res.push_back(current->val);
                current = current->left;
                continue;
            }

            succeed = current-> right;
            while(succeed->left!=NULL && succeed->left!=current)
                succeed = succeed->left;


            if(succeed->left==NULL){
                succeed->left = current;
                res.push_back(current->val);
                current = current->right;
            }

            if(succeed->left==current){
                succeed->left = NULL;
                current = current->left;
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
```