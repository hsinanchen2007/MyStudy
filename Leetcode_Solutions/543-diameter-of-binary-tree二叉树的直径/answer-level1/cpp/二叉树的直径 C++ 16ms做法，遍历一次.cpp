### 解题思路
递归求出每个根节点的左右子树深度的和，找出最大的那个即可。
直接看代码吧，都有注释
![image.png](https://pic.leetcode-cn.com/328a5f159b4e6781a2aad9af2c67380acb4933bc97ac9b06e4ec9f56bb3c46a5-image.png)

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
    int res;
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        res=0;
        search(root);//递归调用
        return res;
    }
    int search(TreeNode* root)
    {   
        int left_deep=0;//初始化
        if(root->left!=NULL) left_deep=search(root->left);//递归调用左子树
        int right_deep=0;//初始化
        if(root->right!=NULL) right_deep=search(root->right);//递归调用右子树
        res = left_deep + right_deep > res ? left_deep + right_deep : res;//求最大的左右子树深度和
        if(root->left==NULL && root->right==NULL) return 1;//叶子节点，返回1，是递归结束的标志
        else return max(left_deep+1,right_deep+1);//非叶子节点，则返回左右子树深度较深的那个，记得要+1，因为经过本身的这个根节点
    }
};
```