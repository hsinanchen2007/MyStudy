### 解题思路
C# 递归优先搜索右侧子树

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
    int result =-1;

    public int KthLargest(TreeNode root, int k) {
        DepthFirstSearch(root, ref k);
        return result;
    }

    public void DepthFirstSearch(TreeNode node, ref int k)
    {
        // 递归结束条件
        if(node == null)
        {
            return;
        }

        // 搜索树大节点永远在右侧，优先搜索右侧
        DepthFirstSearch(node.right, ref k);
        // 到达递归最深处后开始逐级递减k
        k--;
        if(k==0)
        {
            // 从右侧最深处k递减为0，即为所求
            result=node.val;
        }
        if(k>0)
        {
            // 右侧最深处搜索完毕，k仍未满足，优先搜索右侧子树的左子树
            DepthFirstSearch(node.left, ref k);
        }
    }
}
```