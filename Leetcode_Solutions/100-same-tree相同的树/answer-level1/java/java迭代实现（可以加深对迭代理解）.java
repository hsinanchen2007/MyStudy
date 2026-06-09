### 解题思路
- 首先来分解题目，两棵树相同，分到每一层下面其实就是每个节点相同，以及它的左右节点相同，这样遍历到两棵树的最后，得解
- 两个节点有多少种情况？ A、B节点为例子 ， 
    - 1.A == null && B == null （有两种情况，a遍历到最后节点，两者为空 b有可能接下来还有别的节点比对，所以不能贸然返回true，可以好好理解下这句话）
    - 2.A == null || B == null 这种肯定是false
    - 3.A != null && B!= null （接下来无非就是A和B的值相不相等）
- 废话少说，直接上代码
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
        //对入参进行一个判断，才进行到主遍历流程，由于入参已经分开，比较难用哨兵节点进行处理
        //两个都为空，没必要走下去了
        if (p == null && q == null) return true;
        if(p == null || q == null){
            return false;
        }
        if(p.val != q.val)return false;

        Queue<TreeNode> q1 = new LinkedList<>();
        Queue<TreeNode> q2 = new LinkedList<>();
        q1.add(p);
        q2.add(q);
        //主流程，主要对出错进行判断，如果主流程走下来没出错，证明两棵树匹配上了
        while (!q1.isEmpty()) {
            p = q1.poll();
            q = q2.poll();
            if(p == null || q == null){
                if(p == null && q == null){
                    continue;//重点看此处，好多人会把牵出一个函数进行判断，调用完还需要进行一次判断，以及对空值判断
                    //此处有效避免了null，两者null时候跳过就是了，主流程会保证是否遍历到最后的节点
                }
                return false;
            }
            if(p.val != q.val )return false;
            q1.add(p.left);
            q2.add(q.left);
            q1.add(p.right);
            q2.add(q.right);
      }
      return true;
    }
    

}
```
- 既然成对出现，为啥不可以尝试使用一个queue去优化
```java
     public boolean isSameTree(TreeNode p, TreeNode q) {
        if (p == null && q == null) return true;
        if(p == null || q == null){
            return false;
        }
        if(p.val != q.val)return false;
        Queue<TreeNode> queue = new LinkedList<>();
        queue.add(p);
        queue.add(q);
        while (!queue.isEmpty()) {
            p = queue.poll();
            q = queue.poll();
            if(p == null || q == null){
                if(p == null && q == null){
                    continue;
                }
                return false;
            }
            if(p.val != q.val )return false;
            queue.add(p.left);
            queue.add(q.left);
            queue.add(p.right);
            queue.add(q.right);
      }
      return true;
    }
```