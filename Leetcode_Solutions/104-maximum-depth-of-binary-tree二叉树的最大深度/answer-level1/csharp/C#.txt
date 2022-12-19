### 解题思路
C#的队列`Queue<int>`
进队列Enqueue
出队列Dequeue
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
    public int MaxDepth(TreeNode root) {
            if(root==null) return 0;
        var t = new Queue<TreeNode>();
            var tv = new Queue<int>();
            t.Enqueue(root);
            tv.Enqueue(1);
            int res  = 0;
            while(t.Count!=0){
                    var tmp = t.Dequeue();
                    var tmpv = tv.Dequeue();
                    res = Math.Max(res,tmpv);
                    if(tmp.left!=null)
                    {
                            t.Enqueue(tmp.left);
                            tv.Enqueue(tmpv+1);
                    }
                    if(tmp.right!=null){
                       t.Enqueue(tmp.right);
                        tv.Enqueue(tmpv+1);
                    } 
            }
            return res;
    }
}
```