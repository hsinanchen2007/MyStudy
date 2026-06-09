```
class Solution {
    public int sumEvenGrandparent(TreeNode root) {
        int result = 0;
        if(root == null) return 0;
        LinkedList<TreeNode> q = new LinkedList<>();
        q.add(root);

        while (!q.isEmpty()){
            TreeNode temp = q.pollFirst();
            result += getOkGrandsonSum(temp);
            // result += getGrandsonSumIf(temp, t->t.val%2==1);

            if (temp.left != null)
                q.add(temp.left);
            if (temp.right != null)
                q.add(temp.right);
        }
        return result;
    }
    private int getOkGrandsonSum(TreeNode node){
        if(node == null || node.val % 2 != 0) return 0;
        return getSonSum(node.right) + getSonSum(node.left);
    }
    private int getGrandsonSumIf(TreeNode node, Function<TreeNode, Boolean> function){
        if(node == null || function.apply(node)) return 0;
        return getSonSum(node.right) + getSonSum(node.left);
    }
    private int getGrandsonSum(TreeNode node){
        if(node == null) return 0;
        return getSonSum(node.right) + getSonSum(node.left);
    }
    private int getSonSum(TreeNode node){
        int result = 0;
        if(node == null) return 0;
        if(node.right != null) result = node.right.val;
        if(node.left != null) result += node.left.val;
        return result;
    }
}
```
遍历，对val是偶数的节点的孙子的值求和。
