### 解题思路
此处撰写解题思路
1. 创建一条辅助的ArrayList，并将两个链表的值统统add()进ArrayList
2. 将ArrayList用Collections接口的sort()方法，从小到大排序
3. 通过遍历ArrayList，一边用当前数值创建新的ListNode，一边建立上一个节点和当前节点的next关系，从而形成一条新的链表(合并并且sort过的)
4. 最终返回新建好的链表的head

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
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        ArrayList<Integer> list = new ArrayList<Integer>();
        
        ListNode temp = l1;
        while(temp != null){
            list.add(temp.val);
            temp = temp.next;
        }
        
        ListNode temp1 = l2;
        while(temp1 != null){
            list.add(temp1.val);
            temp1 = temp1.next;
        }
        
        Collections.sort(list);
        
        ListNode head = null;
        ListNode prev = null;
        for(int i=0; i<list.size(); i++){
            ListNode curr = new ListNode(list.get(i));
            if(i == 0){
                prev = curr;
                head = curr;
            }
            else{
                prev.next = curr;
                prev = curr;
            }
        }
        return head;
    }
}
```