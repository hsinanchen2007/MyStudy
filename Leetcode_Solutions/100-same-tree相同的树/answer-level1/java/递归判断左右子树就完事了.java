### 解题思路
递归思想，两颗树一样的条件是左右子树都一样。不断递归下去，最后判断单一的节点值就行了。

### 代码

```java

class Solution {

    public boolean isSameTree(TreeNode p, TreeNode q) 
    {
        if(p==null&&q==null)return true;
        if(p==null||q==null)return false;
        if(p.val!=q.val)return false;

        return isSameTree(p.left,q.left)&&isSameTree(p.right,q.right);
    }
}
```