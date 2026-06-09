


class Solution(object):
    def countAndSay(self, n):
        """
        :type n: int
        :rtype: str
        """
        last_val = "1"
        if n == 1:
            return last_val
        for i in range(2, n+1):
            last_val = self.countLast(last_val)
        return last_val
    
    def countLast(self, last_val):
        ret_list = []
        s = last_val[0]
        cntr = 1
        i = 1
        while i < len(last_val):
            if last_val[i] == s:
                cntr += 1
            else:
                ret_list.append('%d%s'%(cntr, s)) 
                s = last_val[i]
                cntr = 1                
            i += 1
        # ...
        ret_list.append('%d%s'%(cntr, s))
        return ''.join(ret_list)