![微信图片_20190926114553.png](https://pic.leetcode-cn.com/bd3bb3643483ea4e879c382d3f8fc725832b90c2816c6a693060687cc6fedc71-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20190926114553.png)


```java []
class BSTIterator {

    public TreeNode root;
    public boolean isOver;
    public BSTIterator(TreeNode root) {
        this.root = root;
        this.isOver = true;
    }
    
    /** @return the next smallest number */
    public int next() {
        if(root == null){
            return -1;
        }
        TreeNode cur = root;
        TreeNode cur2 = null;
        while(cur != null){
            cur2 = cur.left;
            if(cur2 != null){
                while(cur2.right != null && cur2.right != cur){
                    cur2 = cur2.right;
                }
                if(cur2.right == null){
                    cur2.right = cur;
                    cur = cur.left;
                    continue;
                }else{
                    cur2.right = null;
                }
            }
            root = cur.right;
            return cur.val;
        }
        return -1;
    }
    
    /** @return whether we have a next smallest number */
    public boolean hasNext() {
        if(root != null){
            return true;
        }
        return false;
    }
}
```

