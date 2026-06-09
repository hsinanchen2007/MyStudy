### 解题思路
计算整个树的坡度，需要将每个节点的坡度加起来，也就是说，我们需要找出每个节点的左子树上所有节点的值的和 以及 右子树上所有结点的值的和。
定义一个helper函数，返回当前节点以及左右子树的节点值的和。
定义一个变量tilt，保存整棵树的坡度，每次得到左右子树的节点和时，更新tilt。
此题与[543.二叉树的直径](https://leetcode-cn.com/problems/diameter-of-binary-tree/solution/di-gui-qiu-jie-er-cha-shu-de-zhi-jing-by-jesse-42/)类似，都需要以每个节点为根节点，进而计算某个值。

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
    int helper(TreeNode* root,int &tilt)
    {
        if(root==NULL)  return 0;
        int left=helper(root->left,tilt);
        int right=helper(root->right,tilt);
        tilt+=abs(left-right);
        return left+right+root->val;
    }
    
    int findTilt(TreeNode* root) {
        int tilt=0;
        helper(root,tilt);
        return tilt;
    }
};
```