# 1.祖先字典（父指针）
## 1.1 分析
- 遍历二叉树，建立Map存各个结点的父节点，key为当前节点，value为其父节点。
- 通过Map找到p节点到root的路径（包括p），存入Set。
- 沿着q节点到root的路径往上找，直到路径上某节点在Set中，极为LCA。

## 1.2 代码
```java
import java.util.*;
class Solution {
    HashMap<TreeNode, TreeNode> map = new HashMap<>();
    //先序遍历建立map，递归，也可以用stack
    public void setMap(TreeNode root){
        if(root == null) return;
        if(root.left != null){
            map.put(root.left, root);
        }
        if(root.right != null){
            map.put(root.right, root);
        }
        setMap(root.left);
        setMap(root.right);
    }
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        if(root == null || p == null || q == null) return null;
        if(p == q) return p;
        map.put(root, null);
        setMap(root);
        HashSet<TreeNode> set = new HashSet<>();
        //p到root的路径，包括p
        while(map.containsKey(p)){
            set.add(p);
            p = map.get(p);//p的父节点
        }
        //沿着q到root的路径，查看set中是否存在相同的节点，极为最近公共祖先
        while(!set.contains(q)){
            q = map.get(q);//q的父节点
        }
        return q;
    }
}
```

## 1.3 复杂度
时间：O(n),建立字典要遍历所有节点
空间：O(h)，h为树高，辅助空间为
