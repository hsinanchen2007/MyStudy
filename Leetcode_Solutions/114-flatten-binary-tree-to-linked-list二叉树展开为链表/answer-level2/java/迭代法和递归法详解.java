**方法1：迭代法**

展开后的链表就是原二叉树前序遍历的顺序，所以我们可以顺着前序遍历的思路开始思考。根据题意，如果左子树非空，就将左子树置为根节点的右子树，而原来的右子树则跟在**左子树前序序列的最后一个节点**。其原理示意图如下：
![image.png](https://pic.leetcode-cn.com/a32c919ea2e3a3211696d1f1ea81ad7ed9dc1829d984c412fb523fae84174d3a-image.png)

我们举一个具体的例子，看看大概的执行过程：（ps：图画得我好累~）

step 1:
![image.png](https://pic.leetcode-cn.com/69d0c484e893e5c56a0f37eab8fedb15d7d3276046399509b473c11480d3c379-image.png)

step 2: 
![image.png](https://pic.leetcode-cn.com/03fc792903ce989659961603ee48f0094cc6f6f91f7e11555c9816d75f0a4853-image.png)

step 3:
![image.png](https://pic.leetcode-cn.com/00751b7ce9d086fc2f6c8b6e8934efccd908a1d6ae3505dbe6de02376e978f38-image.png)

step 4: 图略，同step 3一样，只是更新了curr

step 5:
![image.png](https://pic.leetcode-cn.com/c8da81b9401fe14779096df4462a5bff569020ef040803939bf81035a8f3b641-image.png)

至此，别的我就不多说了，结合代码好好体会，并且自己也模拟一遍。

代码：
```java
class Solution {
    public void flatten(TreeNode root) {
        TreeNode curr = root;
        while(curr != null) {
            if(curr.left != null) {
                // find rightest node of left subtree
                TreeNode last = curr.left;
                while(last.right != null) {
                    last = last.right;
                }
                // reconnect
                last.right = curr.right;
                curr.right = curr.left;
                curr.left = null; // don't forget
            }
            // update curr
            curr = curr.right;
        }
    }
}
```

**方法2：递归法**
要说迭代法自己还能想想，递归法我是完全想不出来，并且在第二次写的时候仍然没有想到这个方法。答案来自leetcode原站点高票回答。（我只是搬运工，参考链接见最后）

这种方法的关键思想在于通过递归自底向上实现，本质上和后序遍历没有区别，只不过这里稍稍做了一些变形，遍历的顺序为：右子树 -> 左子树 -> 根。

代码：
```java
class Solution {    
    TreeNode prev = null;
    public void flatten(TreeNode root) {
        if(root == null) return;
        flatten(root.right);
        flatten(root.left);
        root.right = prev;
        root.left = null;
        prev = root;
    }
}
```
过程示意图：(示意图也是直接搬运的...LOL)
```
        1
       / \
      2   5
     / \   \
    3   4   6
    -----------        
    pre = 5
    cur = 4
    
        1
       / 
      2   
     / \   
    3   4
         \
          5
           \
            6
    -----------        
    pre = 4
    cur = 3
    
        1
       / 
      2   
     /   
    3 
     \
      4
       \
        5
         \
          6
    -----------        
    cur = 2
    pre = 3
    
        1
       / 
      2   
       \
        3 
         \
          4
           \
            5
             \
              6
    -----------        
    cur = 1
    pre = 2
    
    1
     \
      2
       \
        3
         \
          4
           \
            5
             \
              6    
```

---
参考：
1. https://leetcode.com/problems/flatten-binary-tree-to-linked-list/discuss/37010/Share-my-simple-NON-recursive-solution-O(1)-space-complexity!
2. https://leetcode.com/problems/flatten-binary-tree-to-linked-list/discuss/36977/My-short-post-order-traversal-Java-solution-for-share

---
自己在时隔2个月后重写这个题，意识里知道这个题可以用递归来做，但是又想不出上面说的那个精妙的递归解法。根据自己的思路，写出了如下这个杂交版的答案，哈哈哈，不要学我。
```java
class Solution {
    public void flatten(TreeNode root) {
        dfs(root);
    }
    
    private TreeNode dfs(TreeNode root) {
        if(root == null) return null;
        TreeNode left = dfs(root.left);
        TreeNode right = dfs(root.right);
        if(left != null) {
            TreeNode curr = left;
            while(curr.right != null) {
                curr = curr.right;
            }
            curr.right = right;
            root.right = left;
            root.left = null;
        }
        return root;
    }
}
```
