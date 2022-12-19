题目示例刻意选择了2，是为了避免给大家提示，也为了误导大家。
事实上，若一号玩家选择了一个结点X，**若该二叉树存在一个解满足题意**，那么在X的父节点，X.left或者X.right中一定存在一个结点满足要求。
若你理解了上面那句话，那么该问题就转换为：
1. 求出不包含X及其子树的结点的总个数，记为upX;
2. 求出X的左子树的结点总个数，记为downXLeft;
3. 求出X的右子树的结点总个数，记为downXRight;

那么若满足以下三种情况，二号玩家就存在必胜解：
1. upX > downXLeft + downXRight + 1;此时二号玩家选择X的父节点必胜；
2. downXLeft > upX + downXRight + 1;此时二号玩家选择X的左孩子必胜；
3. downXRight > upX + downXLeft + 1;此时二号玩家选择X的右孩子必胜；

代码：
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
    private int upX;
    private int downXLeft;
    private int downXRight;

    public boolean btreeGameWinningMove(TreeNode root, int n, int x) {
        upX = find(root, x);

        // case 0
        if(upX > (downXLeft + downXRight + 1)){
            return true;
        }

        // case 1
        if(downXLeft > (upX + downXRight + 1)){
            return true;
        }

        // case 2
        if(downXRight > (upX + downXLeft + 1)){
            return true;
        }

        return false;
    }

    private int find(TreeNode root, int x){
        if(root == null)return 0;
        if(root.val == x){
            downXLeft = findDownX(root.left);
            downXRight = findDownX(root.right);
            return 0;
        }
        return find(root.left, x) + find(root.right, x) + 1;
    }

    private int findDownX(TreeNode root){
        if(root == null)return 0;
        return findDownX(root.left) + findDownX(root.right) + 1;
    }
}
```
所有的Java提交中双100%：
![图 结果]](https://pic.leetcode-cn.com/addf62048db999eecbf4c93376a0852dc9d45381e9130e2965b5ff72a573cad9-tmp.PNG)
