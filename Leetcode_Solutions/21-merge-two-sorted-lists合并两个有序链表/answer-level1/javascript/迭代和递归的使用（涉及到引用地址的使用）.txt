### 迭代

```
/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
var mergeTwoLists = function(l1, l2) {
    // 1.创建两个链表，l为总链表
    var l = new ListNode(0);
    // p 为指针链表
    var p = l;

    // 2.判断链表是否为空，可以不使用 ＝＝ null，直接判断链表就可，因为null就＝＝false
    if(!l1 || !l2) {
        return l = l1 == null ? l2 : l1;
    }
    // 3.当两个链表都没有走到头时
    while(l1 && l2) {        
        if(l1.val <= l2.val) {
            // 让p的下一个指针等于新值
            p.next = new ListNode(l1.val);
            // 移动p到下一个
            p = p.next;
            l1 = l1.next;
        } else {
            
            p.next = new ListNode(l2.val);
            p = p.next;
            l2 = l2.next;
        }
    }
    // 4.当仍有一个链表没有走到头
    if(l1) {
        p.next = l1;
    } else if(l2) {
        p.next = l2;
    }
    // 5.返回第一个节点后的链表，因为创建链表时给它的第一个节点赋了0
    return l.next;
};
```
### 递归
```
var mergeTwoLists = function (l1, l2) {
    // 作为初始存在空链表的判断条件 和 l1、l2链表指针走到最后的返回条件
    if (l1 == null) return l2;
    if (l2 == null) return l1;
    // 排序插入
    // 递归移动l1和l2的节点，走到最后一个节点再开始返回，而此时l1和l2的指针也在最后
    // 继续递归返回l1和l2的值
    if (l1.val < l2.val) {
        l1.next = mergeTwoLists(l1.next, l2);
        return l1;
    } else {
        l2.next = mergeTwoLists(l1, l2.next);
        return l2;
    }
};
```
