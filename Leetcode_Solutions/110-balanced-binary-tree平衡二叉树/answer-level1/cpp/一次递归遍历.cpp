一次递归遍历即可：
思路：
判断根结点左右字数高度
16ms
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
    bool isBalanced(TreeNode* root) {
        int num=0;
        return judge(root, num);
    }
    bool judge(TreeNode* root, int &num){
        if(root==NULL){
            num=0;
            return true;
        }
        if(judge(root->left, num)){
            int l=num;
            if(judge(root->right, num)){
                int r=num;
                if(abs(l-r)<=1){
                    num=max(l, r)+1;
                    return true;
                }else return false;
            }else return false;
        }
        return false;
    }
};
```
