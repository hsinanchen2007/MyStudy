### 解题思路
此处撰写解题思路
使用ArrayList作为缓冲区，两个指针分别指向当前节点与下一个节点。用方法判定每一个元素是否与已出现过的元素重复，重复则不添加，链表长度不变，替换单签指针所指节点的下一节点为下下一个节点。若不重复，则链表长度增加，两个指针都向后移动一位，直到第二个指针所指的元素为空。

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
    public ListNode removeDuplicateNodes(ListNode head) {
        if(head==null)return null;
       ArrayList<Integer> integers = new ArrayList<>();
        addList(integers,head.val);
        int befsize=integers.size();
        ListNode temp1=head;
        ListNode temp2=head.next;
        while (temp2!=null){
            
            addList(integers,temp2.val);
            if (integers.size()==befsize){
                temp1.next=temp2.next;
                temp2=temp2.next;
            }else{
                befsize=integers.size();
                temp1=temp2;
                temp2=temp2.next;
            }
        }
        return head;
    }

    public void addList(List<Integer> list,int a){
        for (Integer integer : list) {
            if (integer==a)return;
        }
        list.add(a);
    }
}
```