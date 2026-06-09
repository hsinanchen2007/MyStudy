### 解题思路
此处撰写解题思路

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
    public List<List<Integer>> pathSum(TreeNode root, int sum) {
        List<List<Integer>> results = new ArrayList<>();
        if(root==null) return results;
        
        LinkedList<Integer> oneResult = new LinkedList<>();//记录到当前节点的int序列
        int curSum = 0;
        
        Stack<TreeNode> wait = new Stack<>();
        wait.push(root);
        oneResult.add(root.val);
        curSum+=root.val;
        
        TreeNode pre = new TreeNode(0);

        while(!wait.isEmpty()){
            TreeNode cur = wait.peek();
            if(cur.left!=null&&pre!=cur.left&&pre!=cur.right){//有左节点且不是从任意节点来的（因为左节点来的表示左节点处理过了，右节点来的表示左右都处理过了），压入左节点
                wait.push(cur.left);
                
                curSum+=cur.left.val;
                oneResult.add(cur.left.val);

                pre = cur;
            }
            else if(cur.right!=null&&pre!=cur.right){//有右节点且不是从右节点来的，压入右节点
                wait.push(cur.right);

                curSum+=cur.right.val;
                oneResult.add(cur.right.val);

                pre = cur;
            }
            else{//左右节点都不用压入，弹出自己,记录值
                wait.pop();

                if(curSum==sum&&cur.left==null&&cur.right==null){
                    results.add(new LinkedList(oneResult));
                }
                curSum-=cur.val;
                oneResult.removeLast();

                pre = cur;
            }
        }

        return results;

    }
}
```