### 解题思路
屏幕快照 2020-02-17 下午5.04.37
![image.png](https://pic.leetcode-cn.com/6f7542bb30635c5c88e1247b54cf8bb4f19f47e3a5edef08d5bf7cbccc01a8e6-image.png)

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
    //定义变量减枝
    boolean isBalance = true;
    public boolean isBalanced(TreeNode root) {
        if(root==null){
            return true;
        }
        getDepth(root);
        return isBalance;
    }
    private int getDepth(TreeNode node){
        //如果已经找到不平衡的树枝，不需要递归，直接返回
        if(!isBalance){
            return 0;
        }
        if(node == null){
            return 0;
        }
        int left = getDepth(node.left);
        int rignt = getDepth(node.right);
        //判断左右树枝是否平衡，如果不平衡更新减枝变量
        if(Math.abs(left-rignt)>1){
            isBalance = false;
        }
        return Math.max(left,rignt)+1;
    }
}
```