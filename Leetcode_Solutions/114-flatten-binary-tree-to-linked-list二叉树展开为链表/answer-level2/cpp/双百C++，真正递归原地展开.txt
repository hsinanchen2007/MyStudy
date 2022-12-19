### 系统测评
![sendpix0.jpg](https://pic.leetcode-cn.com/2bc39839c1b015260434f16d36bbe32085933c6541f11ed015c2077d0ab3f244-sendpix0.jpg)

### 解题思路
无使用额外空间。仅改变原树指向。
思路：递归撸平根节点
1如果根节点非空
     1.1如果左子树非空
        1.1.1撸平左子树
        1.1.2找到左子树的右尾巴tailer
        1.1.3把右子树转移到tailer的右子树
        1.1.4将左子树转移到右子树（已空出）
        1.1.5放空左子树
        1.1.6撸平tailer的右子树
     1.2如果左子树空
        1.2.1直接撸平右子树
2返回根节点

步骤图解：（懒，动用灵魂画手）
![C4AA8E1917FEDD038E87017A0CA920C6.jpg](https://pic.leetcode-cn.com/49a342f458117ee26a3d298a98a66963dce0f90f9175763affd793694131d8c9-C4AA8E1917FEDD038E87017A0CA920C6.jpg)

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
    void flatten(TreeNode* root) {
        if(root){
            if(root->left){
                flatten(root->left);
                TreeNode *tailer=tail(root->left);
                tailer->right=root->right;
                root->right=root->left;
                root->left=nullptr;
                flatten(tailer->right);
            }else flatten(root->right);        
        }      
    }
    TreeNode* tail(TreeNode *root){
        while (root->right) root=root->right;
        return root;
    }
};
```