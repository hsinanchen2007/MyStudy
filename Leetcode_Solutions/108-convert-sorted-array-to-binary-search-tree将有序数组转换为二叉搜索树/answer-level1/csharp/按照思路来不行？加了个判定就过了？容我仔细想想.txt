### 解题思路
我现在有点懵逼怎么就过了呢？一开始参照官方的跟旁边的大佬的思路，写出来，思路是一样的，只是变量名不一样，为什么不可以呢？后来复制旁边老哥的，贴上去，运行，还是不行，然后加了个left+right的和是单数还是双数的判断，为什么就过了？

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
    public TreeNode SortedArrayToBST(int[] nums)
    {
        return Build(0, nums.Length - 1, nums);
    }
    public TreeNode Build(int left, int right, int[] nums)
    {
        if (left > right)
        {
            return null;
        }
        int mid;
        //int sum = left + right;
        mid =((left + right)%2==0)? left + right / 2:left + right / 2+1;
        //int mid = (left + right) / 2;
        TreeNode root = new TreeNode(nums[mid]);
        root.left = Build(left, mid - 1, nums);
        root.right = Build(mid + 1, right, nums);
        return root;
    }

}
```