执行用时 : 4 ms, 在所有 Java 提交中击败了16.70%的用户
内存消耗 : 39.5 MB, 在所有 Java 提交中击败了100.00%的用户


java实现链表反转

【tmp(null)】->【b(head)】->【a(head.next)】
while每次循环更新后，a指向的节点与后面的链表断开，跳出循环时连上


```
class Solution {
    List<Integer> l = new ArrayList<Integer>();
    public int[] reversePrint(ListNode head) {
        if(head==null) return new int[0];
        if(head.next == null) return new int[]{head.val} ;

        ListNode a = head.next;
        ListNode b = head;
        ListNode tmp = null;
        while(a!=null){
            b.next = tmp;
            tmp = b;
            b = a;
            a = a.next;
        }
        b.next = tmp; //此时b是链表头
        
        int len = 0;
        while(b!=null){
            len++;
            l.add(b.val);
            b = b.next;
        }
        System.out.print(len);
        int[] r = new int[l.size()];
        for(int i=0; i<l.size();i++)
            r[i] = l.get(i);
        return r;
    }

}
```
