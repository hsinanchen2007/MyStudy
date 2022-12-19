### 解题思路
遍历链表，把结果放到数组中，然后再根据数组递归创建树。

### 代码

```csharp
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int x) { val = x; }
 * }
 */
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
    public TreeNode SortedListToBST(ListNode head) {        
        if(head ==null)
        {
            return null;
        }

        List<int> listNums = new List<int>();
        ListNode current = head;
        while(current != null)
        {
            listNums.Add(current.val);
            current = current.next;
        }

        var nums = listNums.ToArray();
        return GenerateBST(nums, 0, nums.Length-1);
    }

    private TreeNode GenerateBST(int[] nums, int start, int end)
    {
        if(start>end) return null;

        int mid = (start + end)/2;
        var node = new TreeNode(nums[mid]);
        node.left = GenerateBST(nums, start, mid - 1);
        node.right = GenerateBST(nums, mid + 1, end);

        return node;
    }
}
```