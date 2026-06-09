既然要遍历整颗树，自然是用递归简单，至于遍历方式，就用最简单的深度遍历即可，思路是递归调用时传入当前节点是否为偶数的布尔值，对子节点递归调用时根据这个布尔变量决定是否将子节点累加到sum中，虽说祖父节点子孙节点涉及到三层树，但这个递归简洁就简洁在每次只访问两层中的节点，用了一个布尔变量来避免对祖父节点的访问
```
class Solution {
    public int sum;
    public int sumEvenGrandparent(TreeNode root) {
        this.sum = 0;
        recur(root, false);
        return this.sum;
    }
    public void recur(TreeNode node, boolean isEvenGrandfather) { // 递归求所有祖父节点值为偶数的节点的和
        if(node.left != null) {
            if(isEvenGrandfather) { // 祖父节点值是否为偶数
                this.sum += node.left.val;
            }
            recur(node.left, node.val %2 == 0); // 对左子树递归
        }
        if(node.right != null) {
            if(isEvenGrandfather) { // 祖父节点值是否为偶数
                this.sum += node.right.val;
            }
            recur(node.right, node.val %2 == 0); // 对右子树递归
        }
    }
}
```
