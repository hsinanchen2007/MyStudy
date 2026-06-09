官方题解的递归并没有构造新的节点，而是类似其给出的迭代法，在两个链表上原地改变next指向。
按照这个思路，相信很多人对这个递归方法的边界条件很不理解。

我的理解：l1.next = mergeTwoLists(l1.next, l2);注意等号左边是l1.next。
        所以接下来边界条件 
        当l1为空时，递归结束。此时l2的链表还剩下几个节点，l2正处于这几个节点的头。所以返回l2意味着带着这几个节点一起返回。
        当l2为空时同理

public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        if (l1 == null) {
            return l2;
        }
        else if (l2 == null) {
            return l1;
        }
        else if (l1.val < l2.val) {
            l1.next = mergeTwoLists(l1.next, l2);
            return l1;
        }
        else {
            l2.next = mergeTwoLists(l1, l2.next);
            return l2;
        }

    }