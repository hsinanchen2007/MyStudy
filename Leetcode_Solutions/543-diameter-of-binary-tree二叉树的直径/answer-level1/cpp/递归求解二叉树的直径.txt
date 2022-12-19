# 解题思路：
需要注意的是最大直径不一定就是经过二叉树原来的根节点，而是要以每个节点为根节点，计算最大直径（左子树高度+右子树高度）。
所以我们需要一个函数depth来计算某个节点的左子树和右子树的高度。
再定义一个变量cnt来保存二叉树的直径。
每次获得左子树和右子树的高度之后，比较cnt和left+right的大小，更新cnt。
此题与[563. 二叉树的坡度](https://leetcode-cn.com/problems/binary-tree-tilt/solution/di-gui-qiu-jie-er-cha-shu-de-po-du-by-jesse-42/)类似。
# 代码：
```
class Solution {
public:
    int depth(TreeNode* root,int &cnt)
    {
        if(root==NULL)  return 0;
        int left=depth(root->left,cnt);
        int right=depth(root->right,cnt);
        //每次获得左子树和右子树的高度之后，比较cnt和left+right的大小，更新cnt
        cnt=max(cnt,left+right);
        return max(left,right)+1;//求左右子树的高度
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL)  return 0;
        int cnt=0;//保存最大直径
        depth(root,cnt);
        return cnt;
    }
};
```
