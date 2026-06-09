```ruby
#
# @lc app=leetcode.cn id=61 lang=ruby
#
# [61] 旋转链表
#

# @lc code=start
# Definition for singly-linked list.
# class ListNode
#     attr_accessor :val, :next
#     def initialize(val)
#         @val = val
#         @next = nil
#     end
# end

# @param {ListNode} head
# @param {Integer} k
# @return {ListNode}
def rotate_right(head, k)
  return head if head.nil? || head.next.nil?
  return head if k == 0
  n = 1
  first = head
  second = head
  # 将哨兵first移动末尾 并计算链表的长度n
  while first.next != nil
    first = first.next
    n += 1
  end
  # 变成环 此时first在原队列的尾, second在原队列的头
  first.next = second
  # 找到新的尾部，第 (n - k % n - 1) 个节点 
  #  新的链表头是第 (n - k % n) 个节点
  for i in 1..(n - k % n)
    second = second.next
    first = first.next
  end

  first.next = nil
  second
end
# @lc code=end
```
