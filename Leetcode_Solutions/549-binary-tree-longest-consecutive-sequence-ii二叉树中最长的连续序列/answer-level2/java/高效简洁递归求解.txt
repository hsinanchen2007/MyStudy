看一下方法注释，应该就很好理解了
```
class Solution {
    
    private int max;
    
    public int longestConsecutive(TreeNode root) {
        max = 0;
        dfs(root, 0);
        return max;
    }
    
    //返回值表示的是父亲节点的最长递增序列和最长递减序列
    private int[] dfs(TreeNode node, int pre){
        if(node == null){
            return new int[]{1, 1};
        }
        int[] left = dfs(node.left, node.val);
        int[] right = dfs(node.right, node.val);
        max = Math.max(left[0] + right[1] - 1, max);
        max = Math.max(left[1] + right[0] - 1, max);
        int incre = 1, decre = 1;
        if(node.val + 1 == pre){
            //更新递增序列长度
            incre = Math.max(left[0], right[0]) + 1;
        }
        if(node.val - 1 == pre){
            //更新递减序列长度
            decre = Math.max(left[1], right[1]) + 1;
        }
        return new int[]{incre, decre};
    }
}
```