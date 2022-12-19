### 解题思路
利用二叉搜索树的性质，中序遍历二叉树，把遍历结果放在一个数组中，因为遍历结果是一个递增序列，所以
得到的数组为有序数组，把数组中的元素前后两两相减，每次相减之后与前一次比较，更新最小值，返回最小值。

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
    public int getMinimumDifference(TreeNode root) {
        int ans=Integer.MAX_VALUE;
        if(root==null) return 0;
        List<Integer> list=new ArrayList<Integer>();
        proOrder(root,list);
        for(int i=0;i<list.size()-1;i++){
             ans=Math.min(ans,Math.abs(list.get(i+1)-list.get(i)));
        }
        return ans;
    }
    public void proOrder(TreeNode root,List<Integer> list){
        if(root==null) return;
        proOrder(root.left,list);
        list.add(root.val);
        proOrder(root.right,list);
    }
}
```