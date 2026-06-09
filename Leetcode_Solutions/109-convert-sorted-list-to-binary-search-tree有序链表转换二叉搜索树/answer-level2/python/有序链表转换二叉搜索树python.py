思路：

这一题我将分享两种方法。

方法一：

借鉴第108题将有序数组转换为二叉搜索树的思想，先将有序链表转化为数组，再使用第108题的方法即可快速解决.
代码如下：
```python
class Solution(object):
    # 本题还可先将链表转化为数组，再用108题方法
     def sortedListToBST(self, head):
        """
        :type head: ListNode
        :rtype: TreeNode
        """
        if head is None:
            return
        head_list = []
        while head:
            head_list.append(head.val)
            head = head.next
        # 调用和第108题一样的动态规划方法
        def buildBST(nums):
            if len(nums)==0:
                return
            # 取nums列表的中间下标值
            mid_index = len(nums)//2
            pNode = TreeNode(nums[mid_index])
            pNode.left = buildBST(nums[:mid_index])
            pNode.right = buildBST(nums[mid_index+1:])
            return pNode
        return buildBST(head_list)


if __name__ == "__main__":
    nums = [-10, -3, 0, 5, 9]
    head = ListNode(0)
    head_copy = head
    for index in nums:
        head_copy.next = ListNode(index)
        head_copy = head_copy.next
    BTree = Solution().sortedListToBST(head.next)
    print(BTree)
```
执行效率也是奇快，达到了100%！

方法二：快慢指针法
我之前也没接触过这个算法，今天看了一些网上的资料，发现这个算法用来找链表的中间结点很方便，所以就想着学习一下。
算法的思路是：
定义一个快指针fast 一个慢指针slow ，快指针一次移动两个结点，慢指针一次移动一个结点
当fast到达链表的尾部结点时，慢指针也就移动到了链表的中间结点
（同化成一个路程问题，同一段路程，A的速度是B的两倍，他们同时出发，当A走完全程时，B也就刚好走过一半）
中间结点找到了，其他的也就类似了。
代码如下：
```python
class Solution(object):
    # 本题采用快慢指针法来获取链表的中间结点
    def sortedListToBST(self, head):
        """
        :type head: ListNode
        :rtype: TreeNode
        """
        if head is None:
            return
        # 主体还是用动态规划方法
        def buildBST(head, tail):
            if head == tail:
                return
            # 分别定义快慢指针
            slow = head
            fast = head
            # 此处是为了获得链表的中间结点，即slow
            while fast.next is not tail and fast.next.next is not tail:
                slow = slow.next
                fast = fast.next.next
            pNode = TreeNode(slow.val)
            pNode.left = buildBST(head, slow)
            pNode.right = buildBST(slow.next, tail)
            return pNode
        return buildBST(head, None)
```
执行效率也算不错，达到了70%+！
