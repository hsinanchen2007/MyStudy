## 重难点题目
* [LeetCode重难点题目总结](https://mp.weixin.qq.com/mp/homepage?__biz=MzI4Njc4MzMwMw==&hid=1&sn=58bf8e995138b26984c05fd51f198196)


**【核心思想】**
* 递归判断

**【思路】**
1. 如果当前两个节点的`val`相等，那么递归判断`checkSubTree(t1.left,t2.left) && checkSubTree(t1.right,t2.right)`
2. 如果当前两个节点的`val`不相等，那么递归判断`checkSubTree(t1.left,t2) || checkSubTree(t1.right,t2)`
3. 最后处理边界条件



**【代码】**
```java
public boolean checkSubTree(TreeNode t1, TreeNode t2) {
    if(t1==null && t2==null)
        return true;
    if(t1==null && t2!=null)
        return false;
    if(t1!=null && t2==null)
        return false;

    if(t1.val==t2.val)
        return checkSubTree(t1.left,t2.left) && checkSubTree(t1.right,t2.right);
    else
        return checkSubTree(t1.left,t2) || checkSubTree(t1.right,t2);
}
```
**【备注】**
* 经过很多读者的指出，发现上述解法虽然能过检测，但是无法解决测试用例是`[1,2,5,4][1,4,5]`的情况，特此修正上述代码，也向广大读者表示抱歉！

```java
public boolean checkSubTree(TreeNode t1, TreeNode t2) {
    if(t1==null && t2==null)
        return true;
    if(t1==null && t2!=null)
        return false;
    if(t1!=null && t2==null)
        return false;

    return help(t1, t2) || checkSubTree(t1.left, t2) || checkSubTree(t1.right, t2);
}

boolean help(TreeNode t1, TreeNode t2) {
    if (t1 == null && t2 == null) 
        return true;
    
    if (t1 == null || t2 == null)
        return false;
    
    return t1.val == t2.val && help(t1.left, t2.left) && help(t1.right, t2.right);
}
```


**【关注微信公众号，带你拿大厂offer】**

![logo_gif.gif](https://pic.leetcode-cn.com/f6d7085de4095860835e77030f7fd659dc589c02e9fbc0ed5e125ca913d1b15f-logo_gif.gif)