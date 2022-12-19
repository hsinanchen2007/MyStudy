### 解题思路
[Leetcode-Java(240+题解，持续更新、欢迎star&留言&交流)]([_109_sortedListToBST.java](https://github.com/pphdsny/Leetcode-Java/blob/master/src/pp/arithmetic/leetcode/_109_sortedListToBST.java))

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
    /**
     * 解题思路：
     * 去有序链表的中间位置作为根节点，将左部生成左子树，右部生成右子树
     * 难点：
     * 1、如何找到链表的中间位置 ==> 两次遍历，第一次使用length记录总长度，第二次取length/2的位置为更觉得
     * 2、如何将一个链表分割成左右两部分独立链表 ==> 变量rightPreNode保存遍历过程中的前置节点，为断链做准备
     * 
     * 对于难点一：也可以用快慢指针定位中间位置
     * 
     * 链表的解法多数是遍历，利用额外的节点保存中间状态
     * 树的解法多数是递归，同样的入参生成左右子树
     * 
     * 执行用时 :2 ms, 在所有 java 提交中击败了48.48%的用户
     * 内存消耗 :38.7 MB , 在所有 java 提交中击败了97.64%的用户
     *
     * @param head
     * @return
     */
    public TreeNode sortedListToBST(ListNode head) {
        if (head == null) return null;
        ListNode next = head;
        int length = 0;
        while (next!=null){
            length++;
            next = next.next;
        }
        if (length==1){
            return new TreeNode(head.val);
        }
        ListNode leftNode = head;
        ListNode rightNode = head;
        ListNode rightPreNode = head;
        for (int i = 0; i < length / 2; i++) {
            rightPreNode = rightNode;
            rightNode = rightPreNode.next;
        }
        //生成根节点
        TreeNode root = new TreeNode(rightNode.val);
        //断开左侧
        rightPreNode.next = null;
        //断开右侧
        rightNode = rightNode.next;
        //生成左右子树
        root.left = sortedListToBST(leftNode);
        root.right = sortedListToBST(rightNode);
        return root;
    }
}
```