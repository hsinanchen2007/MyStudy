解决此题的思路非常简单，其实就是去比较s树每一个节点对应的子树是否和t相同，如果至少有一棵相同就返回true。

因此说白了就两步：
1. 遍历s树。
2. 根据遍历结果，判断俩树是否相等。

```java
class Solution {
    //遍历s树，去比较s树的每一个节点作为根节点对应的子树是否和t相等
    public boolean isSubtree(TreeNode s, TreeNode t) {
        if(s == null){
            return false;
        }   
        return isSame(s, t) || isSubtree(s.left, t) || isSubtree(s.right, t);
    }
    
    //判断s和t两棵树是否相等
    private boolean isSame(TreeNode s, TreeNode t) {
        if(s == null && t == null){
            return true;
        }
        if(s == null || t == null){
            return false;
        }
        return s.val == t.val && isSame(s.left, t.left) && isSame(s.right, t.right);
    }
}
```
如果写递归函数有困难的，可以参考一下我的一个写递归的教程：[三道题彻底搞定递归](http://lylblog.cn/blog/4)
