执行结果：
执行用时 :0 ms, 在所有 Java 提交中击败了100.00% 的用户
内存消耗 :35.6 MB, 在所有 Java 提交中击败了57.14%的用户

比较难想，我也是改之又改修成正果，之间出了很多次小bug。 给大家参考一下

代码如下：
```
public ListNode partition(ListNode head, int x) {
        ListNode prev=new ListNode(0);
        ListNode begin=head;
        ListNode res;
        prev.next=head;
//        下面两个循环找到第一段比x大的链表begin到end
        while (begin!=null&&begin.val<x){//先找到第一个不小于目标值的节点
            prev=prev.next;
            begin=begin.next;
        }
        if (begin==null)return head;
        ListNode end=begin;
        while (end.next!=null&&end.next.val>=x){
            end=end.next;
        }
        if (begin==head)res=(end.next==null)?begin:end.next;//决定返回哪个节点
        else res=head;
        while (end!=null&&end.next!=null){
            if (end.next.val<x){
                prev.next=end.next;
                end.next=end.next.next;
                prev.next.next=begin;
                prev=prev.next;
            }
            else end=end.next;
        }
        return res;
    }
```
