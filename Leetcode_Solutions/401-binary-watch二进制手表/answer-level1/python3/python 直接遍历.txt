首先这题是简单题，我觉得这种解法才是题目想让我们解题的思路
本文思想是先写一个函数计算给定值的二进制的一的个数
然后遍历所有一的个数相加为num的所有小时和分钟

 def readBinaryWatch(self, num: int) -> List[str]:
        
        list1 = []
        
        def count1(n):
            res = 0
            while n!=0:
                n=n&(n-1)
                res+=1
            
            return res
        
        for i in range(12):
            for j in range(60):
                if (count1(i)+count1(j))==num:
                    if j<10:
                        s = str(i)+':0'+str(j)
                    else:
                        s = str(i)+':'+str(j)
                    list1.append(s)
        
        return list1