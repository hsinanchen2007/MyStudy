**思路**
1、取胜的关键是取得一半以上的节点数量，另外数字是无序的，随便填写，所以不考虑数字顺序。总共有n个节点（n为奇数），考虑其一半m = n / 2.
2、一个节点，如果取它的左（右）节点，则左（右）节点的所有节点都是你的。取父节点，则父节点以上的所有节点也都是你的。
3、假设一号玩家选取了x节点，其左节点的节点总数为left，右节点的节点总数为right。考虑一下情况：
a. left > m 或者 right > m, 你只要选取大于一半的那个节点，则必赢
b. left == m 或者 right == m, 无论选取哪个节点，其他另一边节点和父节点都是一号玩家的，一号玩家总数超过一半，都是必输
c. m <= left + right < n, 无论选取哪个节点，其他另一边节点和父节点都是一号玩家的，一号玩家总数超过一半，都是必输
d. left + right < m, 选取父节点，则总数超过一半，则必赢

**实现**
```
class Solution {
    private int left;
    
    private int right;
    
    private int num;

    public boolean btreeGameWinningMove(TreeNode root, int n, int x) {
        num = x;
        dfs(root);
        int half = n / 2;
        if (left > half || right > half || (left + right) < half) {
            return true;
        } else {
            return false;
        }
    }
    
    private int dfs(TreeNode node) {
        int leftNum = 0;
        int rightNum = 0;
        if (node.left != null) {
            leftNum = dfs(node.left);
        }
        if (node.right != null) {
            rightNum = dfs(node.right);
        }
        if (node.val == num) {
            left = leftNum;
            right = rightNum;
        }
        return leftNum + rightNum + 1;
    }
}
```
![image.png](https://pic.leetcode-cn.com/9658168a094b82315cc8b7c49b3af9a8fbbd8b98f408ea74c5437db7af43db94-image.png)
