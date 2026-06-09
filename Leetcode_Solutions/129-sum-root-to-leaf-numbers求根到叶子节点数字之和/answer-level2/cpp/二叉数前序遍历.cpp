### 解题思路
此处撰写解题思路

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
private:
    int sum = 0;
public:
    /*递归前序遍历二叉树*/
    void sumNumbersIner(TreeNode* root, int value){
        if(root != NULL){ 
            value = value*10 + root->val; //当前节点非空，value值为根节点到父节点的value值*10+当前节点的val
            if((root->left == NULL) && (root->right == NULL)){ // 当前节点是叶子节点，sum+value
                 sum = sum + value;
            }
            sumNumbersIner(root->left,value);
            sumNumbersIner(root->right,value);
        }
    }
      
    int sumNumbers(TreeNode* root) {
        int value = 0;
        sumNumbersIner(root, value);
        return sum;
    }
};
```