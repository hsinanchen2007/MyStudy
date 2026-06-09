函数返回一个大小为2的数组，保存了 1、如果从当前节点往左走的最大路径。 2、如果从当前节点往右走的最大路径。
然后同时更新max的值；
```
class Solution {
    int max = 0;
    public int[] helper(TreeNode cur){
        if (cur == null)
            return new int[2];
        int[] l = helper(cur.left);
        int[] r = helper(cur.right);
        int[] tmp = new int[]{l[1] + 1,r[0] + 1};
        max = Math.max(tmp[0],max);
        max = Math.max(tmp[1],max);
        return tmp;
    }
    public int longestZigZag(TreeNode root) {
        helper(root);
        return max - 1;
    }
}
```
