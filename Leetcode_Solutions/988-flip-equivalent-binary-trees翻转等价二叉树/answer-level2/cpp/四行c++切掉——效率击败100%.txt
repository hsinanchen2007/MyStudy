### 解题思路
先放张图镇楼！！！
![84b0ac3f4d7928409e23d7b4e6ecf81.png](https://pic.leetcode-cn.com/5f48da054d3c384c20ce10cc8994b6c71564b84f203cfce5026ef38ee12ec3b9-84b0ac3f4d7928409e23d7b4e6ecf81.png)

简单说说想法：
    没必要真的把树翻转，此题就是判断就好
递归思路如下：
    1.如果两树对应节点均为空，返回true
    2.如果仅有一个为空，返回false
    3.如果均不为空但值不相同，返回false
    4.然后进入递归依次判断左子树和右子树是否可以转换

核心思想：把判断整棵二叉树转化成判断每个点(子问题)，然后写出递归即可。
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
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if(root1==NULL&&root2==NULL) return true;
        if(root1==NULL||root2==NULL) return false;
        if(root1->val!=root2->val) return false;
        return (flipEquiv(root1->left,root2->left)||flipEquiv(root1->left,root2->right))&&(flipEquiv(root1->right,root2->left)||flipEquiv(root1->right,root2->right));
    }
};
```