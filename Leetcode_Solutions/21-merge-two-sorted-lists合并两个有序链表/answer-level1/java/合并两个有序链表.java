### 解题思路
按照题目描述和样例，是将两个链表合并成新的有序链表，但是实际在平台运行的时候，给出的预期结果和题目要求不一致，我这里是按照题目要求做的。
1、判断两个链表是否都为空，是就返回空链表，这里由于节点没有显式的无参构造方法，所以直接返回了l1和l2中的一个
2、将两个链表的内容全部放到一个list集合
3、利用collections的排序功能，将list降序
4、利用链表的头插法，将list的内容重新插入到新的链表，然后输出的结果就是升序

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
    public  ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        if (l1 == null && l2 == null){
            return l1;
        }
        
        
        List<Integer> list = new ArrayList();
        ListNode tmp ;
        if (l1 != null) {
            list.add(l1.val);
            tmp = l1.next;
            while (tmp != null) {
                list.add(tmp.val);
                tmp = tmp.next;
            }
        }
        
        if (l2!= null) {
            list.add(l2.val);
            tmp = l2.next;
            while (tmp != null) {
                list.add(tmp.val);
                tmp = tmp.next;
            }
        }

        Collections.sort(list, Collections.<Integer>reverseOrder());

        ListNode listNode = null;
        for (int i = 0; i < list.size(); i++) {
            listNode = headInsert(list.get(i), listNode);
        }

        return listNode;
    }



    //头节点插入法
    public  ListNode headInsert(int data,ListNode head) {
        ListNode node = new ListNode(data);
        node.next = head;
        head = node;
        return head;
    }

}
```