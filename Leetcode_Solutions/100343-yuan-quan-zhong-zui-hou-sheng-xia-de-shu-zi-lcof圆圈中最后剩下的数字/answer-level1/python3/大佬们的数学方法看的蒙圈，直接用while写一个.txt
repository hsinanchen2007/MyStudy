class Solution(object):
    def lastRemaining(self, n, m):
        """
        :type n: int
        :type m: int
        :rtype: int
        """
        lst = [i for i in range(n)]
        elemet_num = len(lst)
        current = 0

        while elemet_num > 1:
            add_num = (m-1) % elemet_num
            rm_index = current + add_num if current + add_num < elemet_num else current + add_num - elemet_num
            del lst[rm_index]            
            elemet_num = elemet_num - 1
            current = rm_index % elemet_num
            
        return lst[0]