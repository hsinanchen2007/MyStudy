### 解题思路
代码详细注释
大致思路：
1、设置虚拟头结点，方便处理头结点重复问题。
2、如果当前要添加的结点与下一个结点的值是否相等，设置一个临时结点一直遍历值相等的结点，直到temp指向不相等的结点。然后virtual.next = temp; 将重复结点全部删掉。
3、如果当前要添加的结点与下一个结点不重复，不是重复结点。virtual = virtual.next; 
时间复杂度O(n)，空间复杂度O(1)

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
    public ListNode deleteDuplicates(ListNode head) {
         if (head == null){
            return null;
        }
        // 设置虚拟头结点,防止头结点也是重复元素时，删除不好处理。
        ListNode virtual = new ListNode(0);
        virtual.next = head;
        ListNode res = virtual;
        while (virtual.next != null){
            int val = virtual.next.val;
            // 判断virtual.next这个结点的值是否与下一个结点的值相等
            // 如果相等，就把后面与其相等的就全部遍历出来
           if (virtual.next.next != null && virtual.next.next.val == val){
               ListNode temp = virtual.next.next;
               //temp最终指向与val不同的下一个结点或者null
               while (temp != null && temp.val == val ){
                   temp = temp.next;
               }
               virtual.next = temp;
           }else {
               virtual = virtual.next;
           }
        }
        //删除虚拟头结点,返回结果
        return res = res.next;
    }
}
```