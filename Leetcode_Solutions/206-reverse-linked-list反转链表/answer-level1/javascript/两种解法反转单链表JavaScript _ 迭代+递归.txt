### 迭代法解题思路

这道题用迭代法很容易解出来。沿着单链表进行遍历，主要用到了三个变量来保存状态：
- 变量newHead保存已从单链表断开的被反转的链表头部
- 变量head是当前遍历的节点
- 变量postHead保存当前节点的后一个节点，在head改变next指向后，使head可以找到下一个要遍历的节点
注意点：当遍历到最后一个节点时，postHead为null

### 代码
```
var reverseList = function(head) {
    //迭代法
    if(head==null || head.length<2){
        return head;
    }
    var newHead=null, postHead=head.next;
    while(head!=null){
        head.next=newHead;
        newHead=head;
        head=postHead;
        postHead=head || head.next; //当head为null的时候，即没有下一个要遍历的节点时
    }
};
```
### 递归法解题思路

作为一个算法小白，一直不太搞得清楚怎么用递归解题，而且总是一看递归题有点晕。
参考了[这篇文章](http://joequery.me/notes/reverse-linked-list-recursion/)终于有点点懂了（虽然不知道下一道类似的题还会不会）。
首先明确我们的函数的功能是反转单链表，递归函数的返回值应该是反转后的单链表的头指针。
先假设我们已经解决了一个规模小一级的问题。

```
1 -> 2 -> 3 -> 4
head

反转后----------
            newHead
               |
1 -> 2 <- 3 <- 4
|
head
```
如图，以反转1->2->3->4为例，假设我们已经将head.next的单链表成功反转。
当前的问题是如何把当前的头节点head加入到已反转的单链表中，构成一个完整的反转链表。
步骤如下：
- 将2指向1
- 切断1指向2的链
- 返回新的头节点

当然，别忘了定义出口条件：若单链表为空或只有一个节点时，单链表不发生任何变化。

### 代码

```javascript
var reverseList = function(head) {
    //递归法
    if(head==null || head.next==null){
        return head;
    }
    var newHead=reverseList(head.next);
    head.next.next=head;
    head.next=null;
    return newHead;
};
```