执行结果：
通过
显示详情
执行用时 :
3 ms
, 在所有 Java 提交中击败了
62.33%
的用户
内存消耗 :
36 MB
, 在所有 Java 提交中击败了
40.11%
的用户
```
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
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        List<List<Integer>> res = new ArrayList<List<Integer>>();
        if(root==null)return res;
        int i=1;
        LinkedList<TreeNode> ll = new LinkedList<>();
        ll.addLast(root);
        while(!ll.isEmpty()){
            int size = ll.size();
            List<Integer> list = new ArrayList<>(size);
            while(size>0){
                if(i%2==1){
                    TreeNode tn = ll.pollFirst();
                    list.add(tn.val);
                    if(tn.left!=null){
                        ll.addLast(tn.left);
                    }
                    if(tn.right!=null){
                        ll.addLast(tn.right);
                    }
                }
                if(i%2==0){
                    TreeNode tn = ll.pollLast();
                    list.add(tn.val);
                    if(tn.right!=null){
                        ll.addFirst(tn.right);
                    }
                    if(tn.left!=null){
                        ll.addFirst(tn.left);
                    }
                }
                size--;
            }
            i++;
            res.add(list);
        }
        return res;
    }
}
```
