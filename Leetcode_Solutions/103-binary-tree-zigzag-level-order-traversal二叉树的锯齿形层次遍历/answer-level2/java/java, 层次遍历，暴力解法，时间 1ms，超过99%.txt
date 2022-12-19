### 解题思路
给定一个二叉树，返回其节点值的锯齿形层次遍历。（即先从左往右，
  再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。
  思路1，顺着题目来，首先是层次遍历需要使用队列，
   层次遍历默认是 从左到右，但是为了形成之字形，我们可以使用一个 标记
   如果上一次是从左到右，则本次就是从右到走，我们只需要把list进行reverse就可以
   了，层次遍历不需要改，只是每次在层次结束得时候，看是否需要翻转list即可。
   时间复杂度 是对所有节点访问一次是 O(n), 因为使用reverse方法反转数组
   对于n个节点其高度是 log N，需要反转的层数是  LogN/2次，每次需要的时间是 那一层的节点个数/2
   树高度 logn, 需要反转的层是 2，4 ，6.。。。。logN
   每层对应的节点个数是 2^2,2^4, 2^6...  2^i  ,
    所以节点总个数sum =  2^2 + 2 ^4 +... 2^i , 等比数列的和是 sum = 2(1-4^i)/1-4 = 1.5 * 4^i = 4^i
   由于 i = logN, ==> sum = 4 ^logN , 通过数学公式转换得到 sum = 2n, 所以时间复杂度是（n)
      想看公式转换的看这里：https://www.quora.com/How-do-I-prove-2-log-n-n
    空间复杂度是 O(n), 因为使用了返回结果需要返回所有节点

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
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
          List<List<Integer>> ans = new ArrayList<>();
        if (null == root)
            return ans;
        //因为根节点先入队，是左边访问
        boolean left = true;
        LinkedList<TreeNode> queen = new LinkedList<>();
        queen.add(root);
        queen.add(null);
        List<Integer> item = new ArrayList<>();
        TreeNode first;
        while (!queen.isEmpty()){
            first = queen.pollFirst();
            //使用null 来标记一层得结束
            if (first == null ) {
               if (!queen.isEmpty()) queen.add(null);
               if (!left) Collections.reverse(item);
               ans.add(item);
               item = new ArrayList<>();
               left = !left;
               continue;
            }
            item.add(first.val);
            if (first.left != null)
                   queen.add(first.left);
            if (first.right != null)
                queen.add(first.right);
        }
        return ans;
    }
}
```