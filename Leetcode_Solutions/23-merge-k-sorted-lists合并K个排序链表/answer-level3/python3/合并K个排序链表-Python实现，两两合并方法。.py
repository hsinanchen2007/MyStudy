1. 采用两两合并方式，最后合成一个大链表。

2. 另外方法采用截面合并，每次扫一遍截面，然后合成链表，感觉效率比较低，执行超时。实现也较复杂，测试用例拷贝下来手工离线测试都通过了。
 
这里就贴出方法1的实现吧，速度还是有些慢。

class Solution(object):
    def mergeKLists(self, lists):
        """
        :type lists: List[ListNode]
        :rtype: ListNode
        """
        n_lists = len(lists)

        if n_lists == 0:
            return None
        elif n_lists == 1:
            return lists[0]
    
        head_ptr = lists[0]
        for i_list in lists[1:]: # merge with pairs
            head_ptr = self.merge2List(head_ptr, i_list) 
            
        return head_ptr                   

    def merge2List(self, l_list, r_list):
        if not r_list or r_list is None: # do nothing for a empty list
            return l_list 
        if not l_list or r_list is None: # return 2nd if 1st is empty
            l_list = r_list
            return l_list
        
        # l_pptr is left prev pointer
        l_ptr, r_ptr, l_pptr = l_list, r_list, None
        while l_ptr is not None and r_ptr is not None:
            if r_ptr.val < l_ptr.val:
                tmp_ptr, r_ptr = r_ptr, r_ptr.next # keep r_ptr in tmp, move r_ptr forward
                tmp_ptr.next = l_ptr
                if l_pptr is None: # 插在最前 
                    l_pptr = tmp_ptr
                    l_list = l_pptr
                else:
                    l_pptr.next = tmp_ptr
                    l_pptr = l_pptr.next # move forward
            else:
                l_pptr = l_ptr # move left forward 
                l_ptr = l_ptr.next
        if l_ptr is None:
            l_pptr.next = r_ptr
        return l_list      