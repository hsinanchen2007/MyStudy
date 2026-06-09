```
class Solution {
public:    
    int countNodes(TreeNode* root) {
        return root == NULL ? 0 : 1 + countNodes(root->left) + countNodes(root->right);
    }
};
```

![image.png](https://pic.leetcode-cn.com/3a91ebd47b6fe59cc789d6659f2020a96d0b3535c70be3c13c9cd3588bbbe001-image.png)
