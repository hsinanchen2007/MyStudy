![1.JPG](https://pic.leetcode-cn.com/809e156aba1e0a67d91b659f49860c3755f8904c7708748ac6e9e1733080d847-1.JPG)

**此解法运用了，二叉搜索树的从大到小遍历。运用了递归的算法**
**当遍历到第k大节点的时候，将数值赋值给res成员变量**
**返回成员变量res的值即可**

```java
class Solution {
    private int count;
    private int res;
    //找到二叉搜索树的第k大节点值
    //二叉搜索树的自创式排序，先右，再中间，再左边，这样就是从大到小排序
    public int kthLargest(TreeNode root, int k) {
        count = k;
        method(root);
        return res;
    }
    public void method(TreeNode root){
        if(count == 0 || root == null){
            return;
        }
        method(root.right);
        count --;
        if(count == 0){
            res = root.val;
        }
        method(root.left);
    }
}


```
