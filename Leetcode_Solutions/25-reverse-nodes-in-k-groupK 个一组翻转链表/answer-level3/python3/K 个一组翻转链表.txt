每遍历K个元素，然后反转，要标记链表首尾。
1. 反转时要注意，从头开始，每两个元素，把后一个元素的next指针指向前一个元素
2. 到结尾后，头部元素next指针指向尾巴的next元素，头部元素的前一个元素（如果有）指针next指向尾巴。
3. 尾巴元素的next指针已经反转指向前一个。
注意以上几点，链表反转即完成。

class Solution(object):
    def reverseKGroup(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """
        p_ptr, s_ptr = head, head # 前驱和后继指针
        ss_ptr, sp_ptr = None, None
        if k == 1:
            return head
        n = 1
        update_head = True
        while p_ptr is not None: 
            if n == k:
                t_p_ptr = p_ptr.next
                t_s_ptr = t_p_ptr
                new_head = self.reverseList(ss_ptr, s_ptr, sp_ptr, p_ptr)
                if update_head:
                    head = new_head
                    update_head = False
                ss_ptr = s_ptr # 后继的后继  
                p_ptr = t_p_ptr
                s_ptr = t_s_ptr
                n = 1
            else:
                sp_ptr = p_ptr # 前驱的后继
                p_ptr = p_ptr.next
                n += 1  
        return head
        
    def reverseList(self, sbeg_ptr, beg_ptr, send_ptr, end_ptr):
        if beg_ptr == end_ptr: # 单个元素 
            beg_ptr 
        
        # 调转列表指针
        p_ptr = beg_ptr.next
        end_next = end_ptr.next # 提前保存，防止被翻转改变 
        pp_ptr = beg_ptr
        while p_ptr is not None and p_ptr != end_ptr:
            #p_ptr = p_ptr.next
            tmp_ptr = p_ptr.next
            p_ptr.next = pp_ptr
            pp_ptr = p_ptr
            if p_ptr != end_ptr:  # 还没到头，保存下一个，否则不管
                p_ptr = tmp_ptr
            
        beg_ptr.next = end_next
        if sbeg_ptr is not None:
            sbeg_ptr.next = end_ptr
        end_ptr.next = send_ptr
        return end_ptr