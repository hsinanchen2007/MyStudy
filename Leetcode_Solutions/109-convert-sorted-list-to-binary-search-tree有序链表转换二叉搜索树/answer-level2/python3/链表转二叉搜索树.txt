    class Solution:
        def sortedListToBST(self, head: ListNode) -> TreeNode:
            if not head:
                return None
            ans = []
            while head:
                ans.append(head.val)
                head = head.next
            return self.buildtree(ans)
            '''
            mid = self.findmid(head)
            root = TreeNode(mid.val)
            if head == mid: #说明没有左子树
                return root
            root.left = self.sortedListToBST(head)
            root.right = self.sortedListToBST(mid.next)
            return root
            '''
        
        def findmid(self,head):
            if not head:return None
            fast = slow = head
            temp = None
            while fast and fast.next:
                fast = fast.next.next
                temp = slow
                slow =slow.next
            if temp: #断开链表
                temp.next = None
            return slow
        
        


        
        def buildtree(self,nums):
            #if left>right:return None
            if len(nums)==0:return None
            mid = len(nums)//2
            root = TreeNode(nums[mid])
            root.left = self.buildtree(nums[:mid])
            root.right = self.buildtree(nums[mid+1:])
            return root