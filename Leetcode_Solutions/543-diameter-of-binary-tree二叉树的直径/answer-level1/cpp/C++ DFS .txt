### 解题思路
这个题应该是 **[二叉树的最大深度](https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/)** 的变化版，只是换了个说法，没有*求解二叉树最大深度*这么直白而已。

我们来分析一下这个问题。


![图片1](https://pic.leetcode-cn.com/4b4b47fc2b7cb4fe3630a2fd1b1712ab7fe61eddadc3d85b27781b335a525ae4)



很显然的是：二叉树的直径（也就是说任意两节点的距离）所表示的该两个节点，一定是叶子节点。
节点深度越深越好，最初给我的感觉是 `根节点的左子树最大深度与右子树最大深度的求和`。但是仔细一想，又不太对，假如这棵树不平衡，导致根节点的右子树深度过小，这样结果就不太对了。

例如下面这棵树，假如根节点左子树的深度再加大一些，就能看出问题了。

![图片2](https://pic.leetcode-cn.com/019189c09771de0b68db4378631d248ca4102818da7fe25b45a11d852333404e)

不过幸运的是，我们发现规律了，`最大距离的两个叶子节点一定属于同一个祖先节点`。**所以，我们可以在深度优先遍历时，保存每一个子节点的左子树和右子树深度和的最大值**。

### 代码
```cpp
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        maxValue = 0;
        dfs(root);
        return maxValue;
    }
private:
    int dfs(TreeNode* root){
        if(!root) return 0;
        // 获取左子树深度
        int leftMaxDepth = dfs(root->left);
        // 获取右子树深度
        int rightMaxDepth = dfs(root->right);
        // 获取当前最大距离
        maxValue = max(maxValue, leftMaxDepth+rightMaxDepth);
        // 返回当前树的最大深度
        return max(leftMaxDepth,rightMaxDepth) + 1;
    }
private:
    int maxValue = 0;
};
```