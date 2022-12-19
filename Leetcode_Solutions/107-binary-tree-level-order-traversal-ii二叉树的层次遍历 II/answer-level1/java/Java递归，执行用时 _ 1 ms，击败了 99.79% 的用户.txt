### 解题思路
Java
使用递归完成
代码使用了ArrayList类中的 size() 返回数组列表中元素大小
若是当前 Depth+1>size()，则说明之前还未遍历到树的该层
最后使用 Collections.reverse() 反转数组列表
代码不够简洁优雅，仅供参考

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
    public List<List<Integer>> levelOrderBottom(TreeNode root) {
        List<List<Integer>> res = new ArrayList<>();
        res = Deep(root,res,0);
        Collections.reverse(res);
        return res;
    }

    public List<List<Integer>> Deep(TreeNode root,List<List<Integer>> res, int Depth){
        //结点空直接返回
        if(root==null) return res;
        //该层未曾到达过，则添加该层的List<Integer>
        if(res.size()<Depth+1) {
            List<Integer> cur = new ArrayList<>();
            res.add(cur);
        }
        res.get(Depth).add(root.val);

        Deep(root.left,res,Depth+1);
        Deep(root.right,res,Depth+1);
        return res;
    }
}
```