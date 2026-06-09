### 解题思路
第一次写题解，有点小激动
能力实在有限，欢迎大家给点建议
我是用递归的方法解出来的
1、由于是二分搜索树，树左孩子结点都小于根节点，树的右孩子结点都大于根节点
2、先写递归的终止条件，判断到结点为空的时候，就表示查询完毕，树中没有该值，则返回null
3、如果val值小于根节点的val值的话，就递归根节点的左孩子。
4、如果val值大于根节点val值的话，就递归根节点的右孩子

### 代码

```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public TreeNode searchBST(TreeNode root, int val) {
        if(root == null){
            return null;
        }
        else if(root.val < val){
           return  searchBST(root.right,val);
        }
        else if(root.val > val){
           return  searchBST(root.left,val);
        }
        else{
            return root;
        }
    }
}
```