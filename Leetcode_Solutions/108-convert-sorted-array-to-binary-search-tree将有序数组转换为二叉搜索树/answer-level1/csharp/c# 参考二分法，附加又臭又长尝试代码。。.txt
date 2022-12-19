失败的代码，源自尝试自己构造递归行为。没能实现重复动作的具体code，直接导致内部处理困难重重。
我觉得需要想办法学会如何提炼递归的repeat行为，这才是最重要的。

```
public class Solution {
        public TreeNode SortedArrayToBST(int[] nums)
        {
            if(nums == null || nums.Length == 0)
            {
                return null;
            }

            return Helper(nums, 0, nums.Length - 1);
        }

        private TreeNode Helper(int[] nums, int front, int back)
        {
            if(front > back) return null;

            var mid = (front + back) / 2;
            var root = new TreeNode(nums[mid]);

            root.left = Helper(nums, front, mid - 1);
            root.right = Helper(nums, mid + 1, back);

            return root;
        }



        //I'm an idiot to write a long-long bad-smell code.
        // public TreeNode SortedArrayToBST(int[] nums)
        // {
        //     if (nums == null || nums.Length == 0)
        //     {
        //         return null;
        //     }

        //     int midVal = (nums.Length - 1) / 2;
        //     var root = new TreeNode(nums[midVal]);
        //     CreateBinaryTree(0, midVal - 1, root, nums, "left");
        //     CreateBinaryTree(midVal + 1, nums.Length - 1, root, nums, "right");

        //     return root;
        // }

        // private void CreateBinaryTree(int leftPos, int rightPos, TreeNode root, int[] nums, string part)
        // {
        //     if (leftPos < 0 || rightPos < 0 || leftPos > rightPos)
        //     {
        //         return;
        //     }

        //     int mid = (leftPos + rightPos) / 2;
        //     if (part.Equals("left"))
        //     {
        //         root.left = new TreeNode(nums[mid]);
        //         if (leftPos == rightPos)
        //         {
        //             return;
        //         }

        //         int nextMid = (leftPos + mid) / 2;

        //         if (rightPos - leftPos == 2)
        //         {
        //             root.left.left = new TreeNode(nums[leftPos]);
        //             root.left.right = new TreeNode(nums[rightPos]);
        //             return;
        //         }

        //         CreateBinaryTree(leftPos, nextMid - 1, root.left, nums, "left");
        //         CreateBinaryTree(nextMid + 1, rightPos, root.left, nums, "right");
        //     }
        //     else
        //     {
        //         root.right = new TreeNode(nums[mid]);
        //         if (leftPos == rightPos)
        //         {
        //             return;
        //         }

        //         int nextMid1 = (mid + rightPos) / 2;

        //         if (rightPos - leftPos == 2)
        //         {
        //             root.right.left = new TreeNode(nums[leftPos]);
        //             root.right.right = new TreeNode(nums[rightPos]);
        //             return;
        //         }

        //         CreateBinaryTree(leftPos, nextMid1 - 1, root.right, nums, "left");
        //         CreateBinaryTree(nextMid1 + 1, rightPos, root.right, nums, "right");
        //     }
        // }
}
```
