### 解题思路
此处撰写解题思路

从叶子节点开始计算，叶子节点存在三种状态，1.正好1个，2.0个 需要从 父节点借一个，3. 大于1个，需要移动到父节点N-1个。所以父节点移动的数量就是子节点缺失和多余的总和，也等同于步数。

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

    // 记录步数
    private int stepCount = 0;

    public int distributeCoins(TreeNode root) {
        if (root == null) {return 0;}
        moveCoins(root);
        return stepCount;
    }


    /**
    * 移动硬币
    * 子节点开始计算，计算节点多余的硬币数量 = 父节点需要移动的步数, > 0 需要转移给父节点的硬币数量，< 0 表示需要从父节点借的硬币数量
    * 
    */
    public int moveCoins(TreeNode node){
        if (node == null) {
            return 0;
        }
        // 移动左侧子节点
        int leftOverNum = moveCoins(node.left);
        // 移动右侧子节点
        int rightOverNum = moveCoins(node.right);
        // 记录当前节点数量
        int current = node.val;
        // 结算最终该节点最后的数量
        current += leftOverNum + rightOverNum;
        // 计算满足子节点锁需要移动的步数 =  abs left + abs right
        stepCount += Math.abs(leftOverNum) + Math.abs(rightOverNum);
        // 计算本节点富余的数量，留一个自己用，其他的给父元素
        return current - 1;
    }
    
}
```