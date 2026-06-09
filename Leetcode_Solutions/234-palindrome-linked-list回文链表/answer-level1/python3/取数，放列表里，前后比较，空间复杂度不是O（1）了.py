class Solution:
    def isPalindrome(self, head: ListNode) -> bool:
        if head==None or head.next==None:
            return True
        else:
            node=head
            list=[]
            while node:
                a=node.val
                list.append(a)
                node=node.next
            first=0
            last=len(list)-1
            while first<last:
                if list[first]!=list[last]:
                    return False
                else:
                    first+=1
                    last-=1
            return True