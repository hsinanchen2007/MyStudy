### 解题思路
首先判断树边界的特殊情况，p和q是null的情况分两种，一个是同时null那我们就认为树相同（给个true），如果不同是那么必定不同（很好想到）（给个false），
最后筛选一下，条件为：p.val == q.val，然后进行下一次的dfs，用isSameTree分别进行判断，
最后发现条件是&&的关系因为要同时满足才能认为相同的树
总结：判断截止条件，然后找候选结点，找筛选条件去筛选
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
    public boolean isSameTree(TreeNode p, TreeNode q) {
        if(p == null && q == null)  {return true;}
        if(p == null || q == null)  {return false;}
        return p.val == q.val && isSameTree(p.left,q.left) && isSameTree(p.right,q.right);
    }
}
```