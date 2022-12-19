### 解题思路
-   递归实现
    - 终止条件:
        - 某棵树走到空节点 此时返回另一个节点 是否为空
        - 两个节点都不为空 判断值是否相等
            - 相等继续判断左右子树
            - 不行等直接返回

```
class Solution {
    public boolean isSameTree(TreeNode p, TreeNode q) {
        //判断null 情况
        if(p == null)
            return q ==null;
        else if(q == null)
            return p ==null;
        else
            if(p.val == q.val)
                return isSameTree(p.right,q.right)&&isSameTree(p.left,q.left);
            else
                return false;

        
        
         
        
    }
}
```

