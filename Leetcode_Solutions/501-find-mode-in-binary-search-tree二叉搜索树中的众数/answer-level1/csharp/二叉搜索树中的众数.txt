### 解题思路
此处撰写解题思路

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
  //历史元素中众数出现的最大次数
        int maxTimes = 0;
        //当前元素出现的次数
        int curTimes = 0;
        //前驱节点
        TreeNode preNode = null;
        public int[] FindMode(TreeNode root)
        {
            List<int> result = new List<int>();
            GetResult(root, result);
            return result.ToArray();
        }

        private void GetResult(TreeNode root, List<int> result)
        {
            if (root == null)
            {
                return;
            }

            GetResult(root.left, result);
            if (preNode != null)
            {
                curTimes = root.val == preNode.val ? curTimes + 1 : 1;
            }
            else
            {
                curTimes = 1;
            }
            if (curTimes == maxTimes)
            {
                result.Add(root.val);
            }
            else if (curTimes > maxTimes)
            {
                result.Clear();
                result.Add(root.val);
                maxTimes = curTimes;
            }
            preNode = root;

            GetResult(root.right, result);
        }
}
```