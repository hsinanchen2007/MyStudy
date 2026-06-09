### 解题思路
![image.png](https://pic.leetcode-cn.com/86d981175eedd59c98bb719428b6271c6fad5c1918f340625ea75fcd3d7eb215-image.png)

此处撰写解题思路

### 代码

```cpp

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root){
            return NULL;
        }
        DFS(root);
        return root;
    }
    void DFS(TreeNode* node){
        if(!node->left && !node->right){
            return;
        }
        TreeNode* leftTemp = node->left;
        node->left = node->right;
        node->right = leftTemp;
        if(node->left){
            DFS(node->left);
        }
        if(node->right){
            DFS(node->right);
        }
    }
};
```