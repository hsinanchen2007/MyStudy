### 解题思路
方法一：两次遍历链表。第一次遍历确定长度找到中间位置，第二次遍历返回中间节点。时间复杂度：O(n)；空间复杂度：O(1)。
![middle.PNG](https://pic.leetcode-cn.com/cc404cf57b0141385f9dd6d0c69a3c8822814676eb77e7a0a48f20f889a8f564-middle.PNG)

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
    public ListNode middleNode(ListNode head) {
        //思路：两次遍历。
        if(head == null) return null;

        //链表长度
        int length = 0;
        ListNode first = head;
        ListNode second = head;

        //第一次遍历链表：得到其长度
        while(first != null){
            length++;
            first = first.next;
        }

        //得到目标数值所在位置
        int target = length / 2;

        //初始位置
        int index = 0;

        //第二次遍历链表：得到目标元素
        while(second != null){
            if(index == target){
                return second;
            }else{
                second = second.next;
                index++;
            }
        }

        return null;
    }
}
```

方法二：快慢指针法。时间复杂度：O(n)；空间复杂度：O(1)。
![fast.PNG](https://pic.leetcode-cn.com/8063499066eccdbab3e35fd03ec373ad3beb8f90d7140cc810ebd8b127660725-fast.PNG)

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
    public ListNode middleNode(ListNode head) {
        //思路：快慢指针法。慢指针一次移动一步，快指针一次移动两步。当快指针到达末尾时，慢指针正好处于中间位置。

        ListNode slow = head,fast = head;

        while(fast != null && fast.next != null){
            slow = slow.next;
            fast = fast.next.next;
        }

        return slow;
    }
}
```