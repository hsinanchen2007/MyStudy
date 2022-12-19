1、我们用一个新链表储存每次比较的最小值
2、if语句判断每次比较的小值
3、当某一个链表已经全部被比较完时指向null跳出循环
4、用三元判断法对有剩下的链表进行一个指向
5、得到结果

var mergeTwoLists = function(l1, l2) {
    var newNode = new ListNode(-1)
    var newHead = newNode
    // 双指针
    while(l1 && l2){
        if(l1.val >= l2.val){
            newHead.next = l2
            newHead = newHead.next
            l2 = l2.next
        }
        else if(l2.val > l1.val){
            newHead.next = l1
            newHead = newHead.next
            l1 = l1.next
        }
        
    }
    newHead.next = l1 ? l1 : l2
    return newNode.next
};