### 解题思路
开始使用的是dfs遍历，后面参照官方解的思路写了一下二分法求解，
顺便回忆了一下二分搜索与完全二叉树的关系，完全二叉树如果叶子节点全满，则是一个标准的数组
按照二分搜索树划分下来的结果，数组的值全在叶子节点上，

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
    int deep;
    public int countNodes(TreeNode root) {
        if (root == null) {
            return 0;
        }
        deep = getDeep(root);
        int num = (int)Math.pow(2,deep-1);
        for (int i=0;i<num;i++) {
            if (!countLastNum(i,num-1,root)) {
                return i+(int)Math.pow(2,deep-1)-1;
            }
        }
        return (int)Math.pow(2,deep)-1;
    }

    public int getDeep(TreeNode node) {
        int deep = 1;
        while (node.left != null) {
            node = node.left;
            deep++;
        }
        return deep;
    }

    public boolean countLastNum(int curNum, int right, TreeNode root) {
       int left = 0;
       int mid;
       while (left < right) {
           mid = left + (right-left)/2;
           if (curNum <= mid) {
               root = root.left;
               right = mid;
           } else {
               root = root.right;
               left = mid+1;
           }
       }
       if (root == null) {
           return false;
       } 
       return true;
    }
}
```