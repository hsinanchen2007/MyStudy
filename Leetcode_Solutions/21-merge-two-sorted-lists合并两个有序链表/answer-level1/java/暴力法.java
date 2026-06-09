### 解题思路
就是首先把两个链表里的数都存到一个arraylist里，然后再根据这个来构造链表。可以写的简短。直接存，然后排序。

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
        ArrayList<Integer> al=new ArrayList();
        while(l1!=null||l2!=null)
        {
            //System.out.println(al);
            if(l1==null)
            {
                al.add(l2.val);
                l2=l2.next;
            }
            else if(l2==null)
            {
                al.add(l1.val);
                l1=l1.next;
            }
            else 
            {
                if(l1.val<=l2.val)
                {
                    al.add(l1.val);
                    l1=l1.next;
                }
                else 
                {
                    al.add(l2.val);
                    l2=l2.next;
                }
            }
        }
        //System.out.println(al);
        if(al.size()==0) return null;
        ListNode res=new ListNode(al.remove(0));
        if(al.size()>0) res.next=new ListNode(al.remove(0));
        ListNode latter=res.next;
        while(al.size()>0)
        {
            latter.next=new ListNode(al.remove(0));
            latter=latter.next;
        }
        return res;
    }
}
```