```
class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        dummyHead = ListNode(0)
        dummyHead.next = head
        
        if not head or not head.next:
            return head
        # 设置哑结点 从而第一个元素可以相同处理  last指向 哑结点 cur指向第一个
        cur = head
        last = dummyHead 
        
        while cur and cur.next:
            # 出现了重复元素 
            if cur.val == cur.next.val:
                # while循环来解决多个数重复的问题
                while cur.next and cur.val == cur.next.val:
                    cur = cur.next
                # 因为是最后一个元素（重复元素）而 跳出循环之后  直接舍弃最后的元素 置为none
                if not cur.next:
                    last.next = None
                # 某个数的重复处理完毕 进行下一个数 设置cur和last cur指向新的元素 last下一个元素为cur  即跳过了重复元素  再利用外层循环判断
                # cur.val != cur.next.val:
                else:
                    cur = cur.next
                    last.next = cur
            # 普通两个不相等元素 直接往前进一步 
            else:
                last = last.next 
                cur = cur.next
        
        return dummyHead.next
```
