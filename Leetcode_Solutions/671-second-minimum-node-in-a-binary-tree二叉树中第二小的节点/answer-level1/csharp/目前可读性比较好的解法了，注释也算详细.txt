### 解题思路
根节点一定是最小值，所以只需要在左右子树中查看是否存在第二大的节点就好。详情看代码及注释。

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
    //定义一个全局变量，初始化为-1，代表默认情况下不存在第二大的值
        private int secondMinValue = -1;
        public int FindSecondMinimumValue(TreeNode root)
        {
            if (root == null || root.left == null)
            {
                return -1;
            }
            //根据题意root.val = min(root.left.val, root.right.val)
            //最小值一定是根节点
            int firstMinValue = root.val;
            //分别查看左右子树是否存在大于根节点的第二大最小值
            SearchSecondValue(root.left, firstMinValue);
            SearchSecondValue(root.right, firstMinValue);

            return secondMinValue;
        }

        private void SearchSecondValue(TreeNode root, int firstMinValue)
        {
            if (root == null)
            {
                return;
            }
            if (root.val > firstMinValue)
            {
                //secondMinValue == -1代表之前还未发现比根节点大的节点
                //如果secondMinValue!= -1且root.val < secondMinValue 代表已经有比根节点大的值，但是目前的节点是更优解
                if (secondMinValue == -1 || root.val < secondMinValue)
                {
                    secondMinValue = root.val;
                }
            }
            SearchSecondValue(root.left, firstMinValue);
            SearchSecondValue(root.right, firstMinValue);
        }
}
```

![image.png](https://pic.leetcode-cn.com/9eba02552a9966e6562e151a2e85b42adc2bb6f6ae41d3cc84d2f031e75eac24-image.png)
