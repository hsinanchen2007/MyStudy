从链表头开始记录长度为k的链表，用两个指针：
- 当前指针cur_p: 记录当前的遍历位置
- 需要记录的长度为k的链表头指针res_head
用参数length 记录当前res_head和cur_p之前的链表长度，
当length < k: cur_p 后移
否则： res_head和cur_p一起后移。
 
只需要一遍遍历，复杂度为O(n)
```
def getKthFromEnd(head, k):
    length=1
    res_head=head
    cur_p = head
    while cur_p.next:
        if length<k:
            cur_p=cur_p.next
            length+=1
        else:
            res_head=res_head.next
            cur_p=cur_p.next
    return res_head
```
