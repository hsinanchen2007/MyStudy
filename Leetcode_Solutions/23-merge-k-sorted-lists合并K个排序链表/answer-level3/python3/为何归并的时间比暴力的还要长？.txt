这是归并：（执行用时:160ms,在所有Python3提交中击败了42.58%的用户内存消耗:17.3MB,在所有Python3提交中击败了35.02%的用户）

    def mergeKLists(self, lists: List[ListNode]) -> ListNode:
        while len(lists)>1:
            lists2=[]
            for i in range(0,len(lists),2):
                l=lists[i]
                r=lists[i+1] if i+1<len(lists) else None
                lists2.append(self.merge2Lists(l,r))
            lists=lists2
        return lists[0] if lists else None
    def merge2Lists(self,l1,l2):
        head=point=ListNode(0)
        while l1 and l2:
            if l1.val<=l2.val:
                point.next=l1
                l1=l1.next
            else:
                point.next=l2
                l2=l2.next
            point=point.next
        point.next=l1 if l1 else l2
        return head.next

这是暴力：（执行用时:132ms,在所有Python3提交中击败了62.45%的用户内存消耗:18MB,在所有Python3提交中击败了9.09%的用户）

    def mergeKLists(self, lists: List[ListNode]) -> ListNode:
        nums=[]
        for i in lists:
            p=i
            while p:
                nums+=[p.val]
                p=p.next
        nums.sort()
        llist=ListNode(0)
        q=llist
        for i in nums:
            q.next=ListNode(i)
            q=q.next
        llist=llist.next
        return llist