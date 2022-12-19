### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/a4df624b37b6b5691b7e2d7eb623160decfa4d2445a9953e8e37a437827b18f8-image.png)

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
    
    public List<TreeNode> allPossibleFBT(int N) {
        List<TreeNode> result = new ArrayList<TreeNode>();
        // 偶数个节点无法构成满足条件的树
        if (N % 2 == 0){
            return result;
        }
        if (N == 1) {
            result.add(new TreeNode(0));
            return result;
        }
        // 对于奇数N，除去顶点，有n = N-1偶数个点位于叶子
        // n个点分成两组，每组必有至少一个节点，一共有n/2种分法
        // 考虑到偶数没有符合条件的组合方式，因此只有分成两个奇数组是有效的
        // 设i为第一组节点的个数，n - i就是第二个组节点的数量
        // 在考虑组合方式，如 n = 4 时，1和3的组合与3和1的组合本质上相同，可以在一次迭代中完成
        // 所以 n/2 为奇数时，只需要执行(n/2 + 1) / 2 次循环，并在循环内，将这两组节点生成的结果交换顺序即可
        //  n/2 为偶数时，执行 n/4 次即可。
        int n = N - 1;
        int maxIterTimes = (n/2) % 2 == 1 ? (n/2 + 1) / 2 : n / 4; 
        int i = 1;
        for (int iter = 0; iter < maxIterTimes; iter++){
            List<TreeNode> treeNodeList1 = allPossibleFBT(i);
            List<TreeNode> treeNodeList2 = allPossibleFBT(n - i);
            for (TreeNode treeNode1 : treeNodeList1) {
                for (TreeNode treeNode2 : treeNodeList2) {
                    TreeNode treeNode = new TreeNode(0);
                    treeNode.left = treeNode1;
                    treeNode.right = treeNode2;
                    result.add(treeNode);
                    if (i != n-i){
                        TreeNode treeNodeReverse = new TreeNode(0);
                        treeNodeReverse.left = treeNode2;
                        treeNodeReverse.right = treeNode1;
                        result.add(treeNodeReverse);
                    }
                }
            }
            i += 2;
        }
        return result;
    }
}
```