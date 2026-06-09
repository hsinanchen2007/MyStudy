class Solution(object):
    def isHappy(self, n):
        """
        :type n: int
        :rtype: bool
        """
        t = n
        count = 0
        if t ==1:
            return True
        while t>1:
            list1=[]
            while t>0:
                m=t//10
                n=t%10
                list1.append(n)
                t = m
            #循环结束条件 为4
            if len(list1)==1 and list1[0] == 4:
                return False
            list2 = list1[::-1]
            s=0
            for i in range(len(list2)):
                s +=list2[i]**2
            if s==1:
                return True
            else:
                t = s
            count +=1
        
        
        
        