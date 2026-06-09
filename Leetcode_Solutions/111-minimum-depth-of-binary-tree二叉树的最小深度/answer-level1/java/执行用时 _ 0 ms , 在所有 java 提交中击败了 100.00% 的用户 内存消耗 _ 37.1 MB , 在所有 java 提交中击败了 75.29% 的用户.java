![image.png](https://pic.leetcode-cn.com/6b558f0dadb024a016377191bc543a82cc0127d6155f72b3d5b997ffb5d36df2-image.png)


和获取树的最大深度类似，遍历一遍，发现是叶子节点就看下是不是比最小的小，是就更新一下最小值


```java []
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
    //当前层
    int deep = 0;
    //最小结果
    int min = Integer.MAX_VALUE;

    public int minDepth(TreeNode root) {
        if(root==null) return 0;
        getDeep(root);
        return min;

    }

    //获取树的层 ，其实就是遍历整个树
    private int getDeep(TreeNode root) {
        if (root != null) {
            deep++;
            int leftDeep = getDeep(root.left);
            int rightDeep = getDeep(root.right);
            if (leftDeep == 0 && rightDeep == 0) {
                if (min > deep) {
                    min = deep;
                }
            }
            deep--;
            return leftDeep > rightDeep?leftDeep+1:rightDeep+1;
            
        }
        return 0;
    }
}
```

虽然是过了，还是没有官方题解思路清晰 orz..