执行结果：执行用时 :0 ms, 在所有 Java 提交中击败了100.00% 的用户
内存消耗 :37.5 MB, 在所有 Java 提交中击败了81.87%的用户

思路：很快，遍历一遍链表即可，以第一个节点为奇数链表头，以第二个节点为偶数链表头。两者同时不断向后延伸至链表尾部，
然后奇数链表尾接上偶数链表头，返回奇数链表头即可。
     注意：在不使用额外空间的情况下，必须得是同时向后延伸，否则会出现某些节点无法到达的情况。

代码：
```
public ListNode oddEvenList(ListNode head) {
        if (head==null||head.next==null)return head;//没有节点或者一个节点，不用处理
        ListNode head2=head.next;//偶数头，最后把奇数尾接到偶数头
        ListNode oddNode=head;//奇数延伸用的节点
        ListNode evenNode=head2;//偶数延伸用的几点
        //后面存在两个节点，奇数，偶数同时向后延伸一个节点
        while (evenNode.next!=null&&evenNode.next.next!=null){
            oddNode.next=evenNode.next;
            evenNode.next=evenNode.next.next;
            oddNode=oddNode.next;
            evenNode=evenNode.next;
        }
        //后面只存在一个节点，技术节点向后延伸，偶数节点其实也向后延伸了，
        // 不过接的是null，或者说是摒弃了之前的后续节点
        if (evenNode.next!=null){
            oddNode.next=evenNode.next;
            evenNode.next=evenNode.next.next;
            oddNode=oddNode.next;
        }
        //奇数尾连接偶数头
        oddNode.next=head2;
        return head;
    }
```
