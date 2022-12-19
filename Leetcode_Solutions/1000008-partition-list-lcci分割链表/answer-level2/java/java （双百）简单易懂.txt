
翻了评论，翻译一下题目，就是把所有小于x的节点挪到值为x的节点左边，大于的在哪都无所谓。
**思路：遍历一趟链表，分割成两个链表，一个是小于x的，一个是大于等于x的，结束之后拼接起来返回**
```
class Solution {
    public ListNode partition(ListNode head, int x) {
        if(head==null || head.next==null) return head;
        ListNode min=null;//较小的链表尾节点
        ListNode minHead=null;//较小的链表头节点
        ListNode max=null;//较大的链表尾节点
        ListNode maxHead=null;//较大的链表头节点
        ListNode p=head;
        while(p!=null){
            if(p.val<x){
                //初始化
                if(min==null){
                    min=p;
                    minHead=min;
                }else{
                    //较小链表添加元素
                    min.next=p;
                    min=min.next;
                }
                //p后移，min断开后续节点
                p=p.next;
                min.next=null;
            }else{
                if(max==null){
                    max=p;
                    maxHead=max;
                }else{
                    max.next=p;
                    max=max.next;
                }
                p=p.next;
                max.next=null;
            }
        }
        //分情况，有时全部比x打，有时全部比x小，都有的话min的尾节点拼上max的头节点
        if(minHead==null && maxHead!=null){
            return maxHead;
        }else if(maxHead==null && minHead!=null){
            return minHead;
        }else{
            min.next=maxHead;
        }
        return minHead;
    }
}
```
