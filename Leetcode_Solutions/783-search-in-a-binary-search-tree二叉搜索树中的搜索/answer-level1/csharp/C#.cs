### 解题思路
迭代处理起来容易许多，而且注意是二叉搜索树，所以不是完全遍历。
### 代码

```csharp
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
    public TreeNode SearchBST(TreeNode root, int val) {
           var t = new Queue<TreeNode>();
           t.Enqueue(root);
           while(t.Count>0){
                    var tmp = t.Dequeue();
                    if(tmp.val==val){return tmp;} 
                    else if(tmp.left!=null&&tmp.val>val){
                            t.Enqueue(tmp.left);
                    }
                    else if(tmp.right!=null&&tmp.val<val){
                            t.Enqueue(tmp.right);
                    }
            }
            return null;
    }
}
```