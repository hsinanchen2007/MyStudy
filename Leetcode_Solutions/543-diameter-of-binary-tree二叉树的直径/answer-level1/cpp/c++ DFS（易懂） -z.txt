### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int len=0;
    int diameterOfBinaryTree(TreeNode* root)
    {
        depth(root);
        return len;
    }

    int depth(TreeNode* root) {
        if (!root)       return 0;
        int dl=depth(root->left);
        int dr=depth(root->right);
        len=max(len,dl+dr);
        return max(dl,dr)+1;
    }
};
```