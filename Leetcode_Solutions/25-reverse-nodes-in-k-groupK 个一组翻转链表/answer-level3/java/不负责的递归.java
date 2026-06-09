感谢灵魂画法牧师的题解指点。

阅读前提：小白自己生搬硬套的解法，有误可喷，采用需谨慎。由于我还处于摸索阶段，并不对以下内容负任何责任。┓( ´∀` )┏。

由于一直都学不会递归，像链表这种类型的题目是从来没想过去用。然而在链表两辆交换的题目时，看到大佬的递归版本的解释，突然感觉大概也许可以用以下方式分析递归。
PS:目前只用于了链表类型的题目（后面的题目还没刷）,不知道是否适用于其他题目。
因为我本人分析递归题目时，总是去分析一整条调用链，去想哪个地方会返回，返回值是啥。。然后分析分析着，就会乱掉，所以看到这个解法时，感觉就像自己被拯救了。

废话不多说：

递归本质：不断重复做相同的事。

思考递归解法时，不要去思考一级又一级完整的调用栈，应该关注每一级的最小调用单元，抽取递归模型。

模型：

1，返回值：返回值可以将调用单元串起来。

2，最小调用单元（重复单元）：每一级重复做的内容。注：明确调用单元内参与的节点

3，终止条件：最后一级调用单元因终止条件，停止继续增加栈深，返回到上一级调用栈。

题目一：反转链表
分析：
```
1，返回值：已经完成反转链表的头节点。

2，调用单元：设当前需要反转的节点是head。head.next.next = head，将head放置在已完成反转链表的尾部，head.next = null。

3，终止条件：head为空指针或者next为空指针。
```

```
public ListNode reverseList(ListNode head) {
        if(head == null || head.next == null){
            return head;
        }
        ListNode p =  reverseList(head.next);
        head.next.next = head;
        head.next = null;
        return p;
    }
```
题目二：
```
1，返回值：已经完成交换的链表的头节点。

2，调用单元：设需要交换的相邻两个节点是head和next。head连接后面已经完成交换的子链表，next连接head，完成交换

3，终止条件：head为空指针或者next为空指针。也就是当前单元只有一个节点或者没有节点时，无法进行交换。
```
```
public ListNode swapPairs(ListNode head) {
        if(head == null || head.next == null){
            return head;
        }
        ListNode next = head.next;
        head.next = swapPairs(head.next.next);
        next.next = head;
        return next;
    }

```

题目三：

```
1，返回值：已经完成反转链表的头节点。
2，调用单元：设当前需要反转的节点是head,head.next,head.next.next等k个节点。将k个节点反转，并将head.next = 已经完成反转链表的头结点。
3，终止条件：head为空指针或者next为空指针。
```
```
 public ListNode reverseKGroup(ListNode head, int k) {
        int count = k;
        ListNode tmp = head;
        while(count-- > 0){
            if(tmp == null){
                return head;
            }
            tmp = tmp.next;
        }

        ListNode newHead = reverse(head, tmp);
        head.next = reverseKGroup(tmp, k);
        return newHead;
    }
//迭代反转链表
 private ListNode reverse(ListNode head, ListNode tmp) {
        ListNode start = head;
        ListNode pre = null;
        while(start != tmp){
            ListNode pos = start.next;
            start.next = pre;
            pre = start;
            start = pos;
        }
        return pre;
    }
//递归反转链表
    private ListNode reverse(ListNode head, ListNode end) {
        if(head.next == end){
            return head;
        }
        ListNode p = reverse(head.next, end);
        head.next.next = head;
        head.next = null;
        return p;
    }
```
