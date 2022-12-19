# 1. 二叉搜索树
因为二叉树搜索树节点有序，所以问题变得简单。如果节点p比当前节点小，则说明节点p在当前节点的左子树；如果节点p比当前节点大，则说明节点p在当前节点的右子树。

代码思路为：
如果p q的值都小于当前节点的值，则递归进入当前节点的左子树；
如果p q的值都大于当前节点的值，则递归进入当前节点的右子树；
**如果当前节点的值在p q两个节点的值的中间，那么这两个节点的最近公共祖先则为当前的节点。**
![二叉搜索树.png](https://pic.leetcode-cn.com/93894f5bb281abb4062a1f2c3cebc7be113f054b5df85feb27065f8a086331ca-%E4%BA%8C%E5%8F%89%E6%90%9C%E7%B4%A2%E6%A0%91.png)
代码如下，时间复杂度为O(log n)
```cpp
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL)return NULL;
        if(p->val > root->val && q->val > root->val) 
            return lowestCommonAncestor(root->right, p, q);
        else if(p->val < root->val && q->val < root->val) 
            return lowestCommonAncestor(root->left, p, q);
        else return root;
    }
};
```

# 2. 普通二叉树
普通二叉树的节点之间则不一定有序(见下图)。
![image.png](https://pic.leetcode-cn.com/b7d25af7bcd0c2be5d7fa5f6f5d4a0b067a316c2665a1ccff359e2ef4f47c7b6-image.png)
在二叉搜索树时，我们可以通过判断节点p的值与当前节点的值，来判断节点p是否在当前节点的左右子树。
对于普通二叉树我们其实也可以利用递归来实现。

代码思路为：
递归查询两个节点p q，如果某个节点等于节点p或节点q，则返回该节点的值给父节点。
**如果当前节点的左右子树分别包括p和q节点，那么这个节点必然是所求的解。**
如果当前节点有一个子树的返回值为p或q节点，则返回该值。（告诉父节点有一个节点存在其子树中）
如果当前节点的两个子树返回值都为空，则返回空指针。

代码如下，时间复杂度为O(n)
```cpp
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL)return NULL;        
        if(root == p||root == q)return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if(left && right)return root;
        return left ? left : right; // 只有一个非空则返回该指针，两个都为空则返回空指针
    }
};
```