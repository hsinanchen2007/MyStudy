
比起循环遍历，递归遍历会快速很多，只是相对而言空间需求更大。因此，我们尝试用递归解决这个问题。以下解法本质上仍然是二次遍历，但速度会快不少。

这个问题关键在于链表无法直接得到整个链表的长度，要得到就必须遍历一遍，我写了一个函数用于递归计算某节点离最后一个节点之间的节点数`backwardRank(ListNode head)`。这个相当于一次遍历。

然后这题第二个关键就在于判断需要被删除的借点，我用一个名为`hasNSon(ListNode head, int N)`的函数，用于判断某节点是否有N个子节点，第一个没有N个子节点的节点便是我们要删除的节点。

还要需要注意的是极端情况，如n==0，或要删除就是第一个节点的情况，可以尝试通过添加一个盲节点在开头解决，但也可以通过添加if判断语句解决，后者更加方便。

```
class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        if(n==0) return head;
        if(backwardRank(head)-1<n) return head.next;
        if(hasNSon(head,n)){
            head.next = removeNthFromEnd(head.next,n);
        }else{
            head.next = head.next.next;
        }
        return head;
    }

    public boolean hasNSon(ListNode head, int N){
        if(backwardRank(head)-1>N){
            return true;
        }else return false;
    }

    public int backwardRank(ListNode head){
        if(head.next==null){
            return 1;
        }else{
            return 1+backwardRank(head.next);
        }
    }
}
```
