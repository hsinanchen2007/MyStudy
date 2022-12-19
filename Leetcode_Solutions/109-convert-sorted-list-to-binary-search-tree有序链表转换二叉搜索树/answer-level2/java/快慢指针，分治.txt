### 解题思路
两种思路
其一，将有序链表转换为有序数组，然后再转换为BST，用时3ms
其二，直接将有序链表转换为BST，使用断链法
利用快慢指针，找到链表的中点，中点构造新节点，中点前一个节后断开
前后分治，思路和有序数组转BST的类似。用时1ms

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

    // private ListNode head;

    public TreeNode sortedListToBST(ListNode head) {
        //// ArrayList<Integer> list = new ArrayList<>();
        //// while (head != null){
        ////     list.add(head.val);
        ////     head = head.next;
        //// }
        //// Object[] nums = list.toArray();
        //// return sortedListToBST(nums, 0, nums.length - 1);

        // int size = size(head);
        // this.head = head;
        // return sortedListToBST(0, size - 1);
        if (head == null){
            return null;
        }else if (head.next == null){
            return new TreeNode(head.val);
        }
        ListNode pre = head;
        ListNode slow = head.next;
        ListNode fast = slow.next;
        while(fast != null && fast.next != null){
            pre = pre.next;
            slow = slow.next;
            fast = fast.next.next;
        }//slow为中点
        pre.next = null;//断链
        TreeNode root = new TreeNode(slow.val);
        root.left = sortedListToBST(head);
        root.right = sortedListToBST(slow.next);
        return root;
    }

    // public TreeNode sortedListToBST(int left, int right){
    //     if(left > right){
    //         return null;
    //     }
    //     int mid = (left + right) >> 1;
    //     // int mid = left + ((right - left) >> 1);
    //     TreeNode leftNode = sortedListToBST(left, mid - 1);
    //     TreeNode root = new TreeNode(head.val);
    //     head = head.next;
    //     root.left = leftNode; 
    //     root.right = sortedListToBST(mid + 1, right);
    //     return root;
    // }

    // public int size(ListNode head){
    //     int size = 0;
    //     while(head != null){
    //         size++;
    //         head = head.next;
    //     }
    //     return size;
    // }

    //// public TreeNode sortedListToBST(Object[] nums, int left, int right){
    ////     if(left > right){
    ////         return  null;
   // //     }
    ////     int mid = left + ((right - left) >> 1);
    ////     TreeNode root = new TreeNode((int)nums[mid]);
    ////     root.left = sortedListToBST(nums, left, mid - 1);
    ////     root.right = sortedListToBST(nums, mid + 1, right);
    ////     return root;
    //// }
}
```