### 解题思路
![image.png](https://pic.leetcode-cn.com/c977dd4d2953a03552b066614f05fa3a780566cf1b51879d9d85f1cb204f6af3-image.png)

将链表从head结点起依次压入栈中。那么，之后从栈中弹出的结点就已经是逆序的了。

然后，依次比较 ***对应结点的值*** 是否相等即可。

使用栈结构解决该问题有两个优点：**较低的内存消耗**和**易于理解**。

但是，如上图所示，使用栈解决该问题十分耗时。

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
class Solution {
    /**
    **   利用栈的特性——出栈时为原链表的逆序，与顺序的结点值一一比较
    **/
    public boolean isPalindrome(ListNode head) {
        if(head == null || head.next == null) return true;

        //申明栈空间
        Stack<ListNode> nodeStack = new Stack<>();
        ListNode tempNode = head;
        //结点依次入栈
        while(tempNode != null){
            nodeStack.push(tempNode);
            tempNode = tempNode.next;
        }
        //链表头的值 与 栈顶（链表尾）的值作比较
        tempNode = head;
        while(tempNode != null){
            //记录从栈中弹出的结点
            ListNode popNode = nodeStack.pop(); 
            if(popNode.val != tempNode.val){
                //不是回文结构
                return false;
            }
            tempNode = tempNode.next;
        }
	return true;
    }
}
```