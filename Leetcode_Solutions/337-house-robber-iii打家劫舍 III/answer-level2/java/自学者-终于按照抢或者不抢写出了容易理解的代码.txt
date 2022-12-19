### 解题思路
* 按照labuladong题解的指导，采用抢或者不抢的思路去编写
* 优化了抢劫当前店铺的编码写法，便于理解，详情参考代码注释
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
    Map<TreeNode,Integer> memo = new HashMap<>();
    public int rob(TreeNode root) {
       if(root == null) {
          return 0;
       }
       if(memo.containsKey(root)) {
           return memo.get(root);
       }
        // 抢当前这家店，当前店铺抢到的金额加上抢劫下下家店铺的金额总合；
        int robCurrentMoney = root.val;
        // 去打劫左子树的下下个商店
        robCurrentMoney += root.left !=null ? rob(root.left.left) : 0;
        robCurrentMoney += root.left != null ? rob(root.left.right) : 0;
         // 去打劫右子树的下下个商店
        robCurrentMoney += root.right != null ? rob(root.right.left) : 0;
        robCurrentMoney += root.right !=null ? rob(root.right.right) : 0;
        
        // 不抢当前这家店，抢劫下家商店
       int robNextMoney = rob(root.left) + rob(root.right);
       int answer = Math.max(robCurrentMoney,robNextMoney);
       memo.put(root,answer);
       return answer;
    }
      
   
    
}
```