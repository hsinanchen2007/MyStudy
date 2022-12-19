执行结果：
通过
显示详情
执行用时 :
3 ms
, 在所有 Java 提交中击败了
20.99%
的用户
内存消耗 :
35.8 MB
, 在所有 Java 提交中击败了
82.74%
的用户
```
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
        if(head==null||head.next==null)return head;
        if(k==0)return head;
        List<ListNode> list = new ArrayList<ListNode>();
        ListNode p = head;
        do{
           // System.out.println(p.val);
            list.add(p);
            p = p.next;
           //  System.out.println(p.val);
        }while(p!=null);
        int i=list.size();
        //System.out.println("ddd"+(i-k%i)+i);
        if(k%i==0)return head;
        ListNode nh = list.get(i-k%i);
        list.get(i-k%i-1).next=null;
        list.get(i-1).next=head;
        
        return nh;
    }
    
}
```
