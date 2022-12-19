![image.png](https://pic.leetcode-cn.com/d6789e2cf2fe6a491f0d46e17ec3768d217f308b7d86a337b7f3286fc2861ebc-image.png)

考虑递归解法，则首先考虑如何分解问题。
题目给出s和t两树，让我们求解t是不是s的子树，那么：
- t就等于s本身
- t是s的左子树的子树
- t是s的右子树的子树

```java
return isEqual(s,t) || isSubtree(s.left, t) || isSubtree(s.right, t);
```

也就是递归体在于以上三步，因此，根据第一点，我们需要一个判断两树相等的函数（同样使用递归）

问题变成：我们如何判断两树（l、r）相等呢？

- 根节点值相等
- l的左子树和r的左子树相等
- l的右子树和r的右子树相等

```java
if(l.val == r.val)
    return isEqual(l.left,r.left) && isEqual(l.right,r.right);
```

以下是完整代码：

```
    /**
    * 判断两树是否相等
    * @param l
    * @param r
    * @return
    */
private boolean isEqual(TreeNode l, TreeNode r){
    if(l == null && r == null) return true;//两树均空自然相等
    if(l == null || r == null) return false;//一空一非空，自然不等
    if(l.val == r.val)//递归判断
        return isEqual(l.left,r.left) && isEqual(l.right,r.right);
    return false;
}

    /**
    * 判断 t 树是否是 s 树的子树
    * @param s
    * @param t
    * @return
    */
public boolean isSubtree(TreeNode s, TreeNode t) {
    if(s == null && t == null)
        return true;
    if(s == null || t == null) return false;
    if(s.val == t.val){
        return isEqual(s,t) || isSubtree(s.left, t) || isSubtree(s.right, t);
    }
    // 根节点不同，那么就不同考虑s和t相等的情形了
    return isSubtree(s.left, t) || isSubtree(s.right, t);
}
```



