本题属于简单题
主要方法其实可以分为两种
1，动态修改链表1或链表2
2，新开一个链表，链表1与链表2一起跑，并做比较，插入新开的链表
上代码
```
var mergeTwoLists = function(l1, l2) {
    if(l1 &&!l2) return l1;
    if(!l1 && l2) return l2;
    if(!l1 && !l2) return l1;
    let s = Math.min(l1.val,l2.val);
    if(l1.val<=l2.val){
        l1 = l1.next
    }else{
        l2 = l2.next
    }
    let pNode = new ListNode(s);
    let cNode = pNode;
    while(l1 && l2){
        if(l1.val<=l2.val){
            let a = l1.val;
            let dNode = new ListNode(a);
            cNode.next = dNode;
            cNode = cNode.next;
            l1 = l1.next
        }else{
            let a = l2.val;
            let dNode = new ListNode(a);
            cNode.next = dNode;
            cNode = cNode.next;
            l2 = l2.next;
        }
    } 
    if(l1) cNode.next = l1;
    if(l2) cNode.next = l2;
    return pNode;
};
```
这里其实写的有些冗余，插入列表的那部分逻辑可以依照策略模式抽成一个函数来处理。题头的三个if分别对应三种极限值。
最后当l1或l2链表遍历结束之后需要将另一个链表所剩下的那部分插入到新链表中
欢迎讨论
👏👏👏👏
