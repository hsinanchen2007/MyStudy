### 解题思路
迭代遍历，详见代码注释
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
        //创建遍历指针current，初始化指向head
        ListNode current = head;
        //current.next == null表示遍历的指针到达链表尾部
        while(current != null && current.next != null){
            //如果下一个元素的值和当前元素的值相等，就删除后后面的元素
            //特殊尾部节点分析：(最后一次循环)
            //相等的情况  【1 】（current）---> 【1】（current.next）  这个时候 current.next.next ==== null
            if (current.next.val == current.val){
                // current.next = null (直接删除的尾部的元素)
                current.next = current.next.next;
            } else {
                //不相等的情况  【1 】（current）---> 【2】（current.next）  这个时候 current 就移动到了尾部元素
                //循环结束之后 current.next 为null 即为最后一次循环
                current = current.next;
             }
        }
        return head;
    }
}
```