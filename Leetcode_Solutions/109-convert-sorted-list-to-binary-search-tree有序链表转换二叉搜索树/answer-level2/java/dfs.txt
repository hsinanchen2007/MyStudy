### 解题思路
此处撰写解题思路

### 代码

```java
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
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
    public TreeNode sortedListToBST(ListNode head) {
        List<Integer> list = new ArrayList<>();
        while (null != head) {
            list.add(head.val);
            head = head.next;
        }
        int [] array = new int [list.size()];
        for (int i = 0; i < array.length; i++) {
            array[i] = list.get(i);
        }
        return dfs(array,0,array.length - 1);
    }

    public TreeNode dfs(int [] array, int start, int end) {
        if (end < start) {
            return null;
        }
        int mid = (start + end ) / 2;
        TreeNode root = new TreeNode(array[mid]);
        root.left = dfs(array,start,mid - 1);
        root.right = dfs(array,mid + 1, end);
        return root;
    }
}
```