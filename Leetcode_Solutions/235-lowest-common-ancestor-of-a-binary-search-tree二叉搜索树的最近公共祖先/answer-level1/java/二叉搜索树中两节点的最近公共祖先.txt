# 1.递归

## 1.1 分析

BST的特点，各子树的root大于左子树的所有节点，小于右子树的所有节点。根据这个特点，p、q的LCA分为三种情况：
- p、q在root的左子树
- 在右子树
- p、q分别在root的左右子树，此时root即为LCA
- 
## 1.2 代码
```java
class Solution {
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        if(root == null || p == null || q == null) return null;
        if(p == q) return p;
        //左子树
        if(q.val < root.val && p.val < root.val) 
		{
			return lowestCommonAncestor(root.left, p, q);
		}
        //右子树
		else if(p.val > root.val && q.val > root.val) 
		{
			return lowestCommonAncestor(root.right, p, q);
		}
		else{
			return root;
		}
	}
}
```

## 1.3 复杂度
时间：O(h),h为树高
空间：O(h)

# 2.迭代
## 2.1 分析
其实不需要递归，三种情况，前两种LCA在root的一侧时，直接将root指向这一侧的子树，继续循环。  
否则，root即为LCA，退出循环。  
这样可以减少递归浪费的空间。  
## 2.2 代码
```java
class Solution {
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        if(root == null || p == null || q == null) return null;
        int pv = p.val;
        int qv = q.val;
        TreeNode r = root;
        while(r != null){
            if(pv > r.val && qv > r.val){
                r = r.right;
            }
            else if(pv < r.val && qv < r.val){
                r = r.left;
            }
            else{
                break;
            }
        }
        return r;
    }
}
```

## 2.3 复杂度
时间：O(h)，h为树高
空间：O(1)