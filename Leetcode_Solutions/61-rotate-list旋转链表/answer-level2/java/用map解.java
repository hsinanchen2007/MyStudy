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
class Solution {
    public ListNode rotateRight(ListNode head, int k) {
        if(head==null){
            return null;
        }
        ListNode temp=head;
        Map<Integer,ListNode>map=new HashMap<>();
        int count=0;
        while (temp!=null){
            map.put(count++,temp);
            temp=temp.next;
        }
        int index;
        if(k%count==0){
            index=0;
        }else{
            index=count-k%count;
        }
        if(index==0 || count==1){
            return head;
        }else{
            map.get(index-1).next=null;
        }
        if(index==count-1){
            map.get(index).next=head;
        }else{
            map.get(count-1).next=head;
        }



        return map.get(index);
    }
}
```