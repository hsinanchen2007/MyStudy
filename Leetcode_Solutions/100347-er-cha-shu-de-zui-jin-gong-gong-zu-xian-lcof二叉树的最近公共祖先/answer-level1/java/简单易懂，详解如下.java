## 重难点题目
* [LeetCode重难点题目总结](https://mp.weixin.qq.com/mp/homepage?__biz=MzI4Njc4MzMwMw==&hid=1&sn=58bf8e995138b26984c05fd51f198196)


#### 解法1：递归
这是一道纯递归题，递归体很好想到，关键就是边界条件的处理。




**【思路】**
因为lowestCommonAncestor(root, p, q)的功能是找出以root为根节点的两个节点p和q的最近公共祖先，所以**递归体**分三种情况讨论：
1. 如果p和q分别是root的左右节点，那么root就是我们要找的最近公共祖先
2. 如果p和q都是root的左节点，那么返回lowestCommonAncestor(root.left,p,q)
3. 如果p和q都是root的右节点，那么返回lowestCommonAncestor(root.right,p,q)

**边界条件**讨论：
1. 如果root是null，则说明我们已经找到最底了，返回null表示没找到
2. 如果root与p相等或者与q相等，则返回root
3. 如果左子树没找到，递归函数返回null，证明p和q同在root的右侧，那么最终的公共祖先就是右子树找到的结点
4. 如果右子树没找到，递归函数返回null，证明p和q同在root的左侧，那么最终的公共祖先就是左子树找到的结点


**【代码】**
```java
public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
    if(root==null || root==p || root==q)
        return root;
    
    TreeNode leftNode=lowestCommonAncestor(root.left,p,q);
    TreeNode rightNode=lowestCommonAncestor(root.right,p,q);

    if(leftNode==null)
        return rightNode;
    if(rightNode==null)
        return leftNode;

    return root;
}
```
**【备注】**
* 这是一道纯递归问题，如果做过会瞬间出答案；没做过还是要思考一段时间的

**【关注微信公众号，带你拿大厂offer】**

![logo_gif.gif](https://pic.leetcode-cn.com/f6d7085de4095860835e77030f7fd659dc589c02e9fbc0ed5e125ca913d1b15f-logo_gif.gif)
