### 解题思路
**剪枝法**解决。
- 判断是否为平衡二叉树时，先依次看左右子树。如果一旦发生了左右子树中不是平衡的情况，就返回-1.相当于就不再判断了！剪枝！
- 如果左右子树都符合情况，那么根据左右子树的高度差来判断。如果高度差小于等于1，那么向上层返回的就是当前节点的高度，否则返回-1.到了上层后就可以直接返回了。


看着别人提供的这个方法写的，分析来看，理论上这个方法应该快的，然而。。是我三个方法中时间最慢的。。？？

![image.png](https://pic.leetcode-cn.com/07775e126d233ae54f45ddc827e3e14fa8dd13f75a433ad562f2439695d655c0-image.png)


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
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        return help(root)!=-1;
    }

    int help(TreeNode *t){
        if(!t)  return 0;
        int left=help(t->left);
        if(left==-1) return -1; //-1时直接返回
        int right=help(t->right);
        if(right==-1) return -1;
        return (abs(left-right)<2)?max(left,right)+1:-1; //在此判断如果符合平衡条件，返回当前高度，否则-1
    }
};
```