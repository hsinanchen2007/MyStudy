### 递归法 ###
![04.08..gif](https://pic.leetcode-cn.com/0edeee2f145424c9e639e5e3d7cc2fffc2c955a2b6c4cc0b3f6e7a1ca7aee6df-04.08..gif)
#### 思路 ####
##### 分析 #####
- 对于当前的根节点`root`
  - 若`root`为空，直接返回`root`，表示没有找到目标
  - 若`root`为`p`或`q`
    - 若左子树或右子树中含有另外一个目标节点，那么`root`就是最终答案，返回`root`
    - 否则，也应当返回`root`，表示找到了其中一个目标
  - 否则
    - 若左子树和右子树分别含有`p`、`q`中的一个，那么`root`就是最终答案，返回`root`
    - 否则
      - 若两子树中含有`p`或`q`中的一个，即返回那个节点，表示找到了其中一个目标
      - 否则返回`nullptr`，表示没有找到目标
##### 整理 #####
- 经过整理我们发现
  - 若`root`为`p`或`q`，无论子树是否含有另外一个目标，都应该返回`root`
  - 另外，当左右子树的均含有目标节点时，返回`root`，否则只需返回找到的目标节点或空指针
#### 算法 ####
- 若`root`为空或`root == p`或`root == q`，返回`root`
- 分别将`root->left`、`root->right`作为根节点，调用自身，得到返回值`left`、`right`
- 若`left`不为空
  - 若`right`不为空，返回`root`
  - 否则返回`left`
- 否则返回`right`

<![幻灯片1.PNG](https://pic.leetcode-cn.com/936011f6a541b1c4671cd8c6e5c76e1fa6ffa16247f2b835f2e74951eb1d30df-%E5%B9%BB%E7%81%AF%E7%89%871.PNG),![幻灯片2.PNG](https://pic.leetcode-cn.com/652ffde12cdde1bbde573e49c6b59972d526f75a3522edbc0e0705a5d8b023fa-%E5%B9%BB%E7%81%AF%E7%89%872.PNG),![幻灯片3.PNG](https://pic.leetcode-cn.com/5d0bb7fc1dc4d93e27c7d27ab52835b930a95984cd459b6bd7d4f3f0401c6a85-%E5%B9%BB%E7%81%AF%E7%89%873.PNG),![幻灯片4.PNG](https://pic.leetcode-cn.com/378a285c02ba712ba4c17fe4e7c78c866451dc6be4264cd764d1111401279e1e-%E5%B9%BB%E7%81%AF%E7%89%874.PNG),![幻灯片5.PNG](https://pic.leetcode-cn.com/778b37d00a95131f5e695128fbdafb09ad256c1c91efd7a3795f1722fe5f81ec-%E5%B9%BB%E7%81%AF%E7%89%875.PNG),![幻灯片6.PNG](https://pic.leetcode-cn.com/99b4401d7ab709ee0b18a6d4e4f999cdba55f5fd45c0dc40d499a3ef074908c6-%E5%B9%BB%E7%81%AF%E7%89%876.PNG),![幻灯片7.PNG](https://pic.leetcode-cn.com/0871797c27797a4809d0af78fd9f644e87335fe91dbf907e4c8e640a38bb2006-%E5%B9%BB%E7%81%AF%E7%89%877.PNG)>
#### 代码 ####
```c++ []
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root == p || root == q) return root;
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);
        return left ? right ? root : left : right;
    }
};
```
```java []
class Solution {
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        if (root == null || root == p || root == q) return root;
        TreeNode left = lowestCommonAncestor(root.left, p, q);
        TreeNode right = lowestCommonAncestor(root.right, p, q);
        return left != null ? right != null ? root : left : right;
    }
}
```
```python []
class Solution:
    def lowestCommonAncestor(self, root: TreeNode, p: TreeNode, q: TreeNode) -> TreeNode:
        if not root or root == p or root == q: return root
        left = self.lowestCommonAncestor(root.left, p, q)
        right = self.lowestCommonAncestor(root.right, p, q)
        return (root if right else left) if left else right
```
#### 复杂度分析 ####
- 时间复杂度`O(n)`，其中`n`为树的节点总数
- 空间复杂度`O(n)`，递归工作栈需要额外的空间开销