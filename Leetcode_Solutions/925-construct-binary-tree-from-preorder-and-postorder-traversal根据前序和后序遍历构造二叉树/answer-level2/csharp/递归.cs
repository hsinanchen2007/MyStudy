### 解题思路
递归，建议结合另外两道一起看

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
    public TreeNode ConstructFromPrePost(int[] pre, int[] post) {
        return Helper(pre, 0, pre.Length -1, post, 0, post.Length - 1);
    }

    private TreeNode Helper(int[] pre, int preStart, int preEnd, int[] post, int postStart, int postEnd)
    {
        if(preStart > preEnd)
        {
            return null;
        }
        var root = new TreeNode(pre[preStart]);
        if(preStart + 1 <= preEnd)
        {
            int splitIndex = -1;
            for(int i = postStart; i <= postEnd; i++)
            {
                if(post[i] == pre[preStart + 1])
                {
                    splitIndex = i;
                    break;
                }
            }
            root.left = Helper(pre, preStart + 1, splitIndex - postStart + preStart + 1, post, postStart, splitIndex);
            root.right = Helper(pre,splitIndex - postStart + preStart + 2,preEnd,post, splitIndex + 1, postEnd - 1);
        }

        return root;
    }
}
```