利用回溯生产 123类型的连续数。
加一个内循环生产 123、234等同位数的
加一个外循环生产 123、1234等不同位数的

class Solution:
    
    def sequentialDigits(self, low: int, high: int) -> List[int]:
        ln = len(str(low))
        hn = len(str(high))
        res,arr = [],[]

        for num in range(ln, hn+1):
            for i in range(1, 11-num):               
                self.dfs(res, arr, i, num, low ,high)

        return res

    def dfs(self, res, arr, i, num, low ,high):
        if len(arr) == num:
            tmp = "".join(arr)
            if low <= int(tmp) <= high:
                res.append(tmp)
            
            return
  
        arr.append(str(i))
        self.dfs(res, arr, i+1, num, low ,high)
        arr.pop()




不想回溯的话用多一个循环就行

class Solution:
    
    def sequentialDigits(self, low: int, high: int) -> List[int]:
        ln = len(str(low))
        hn = len(str(high))
        arr = [] 
       
       
        for bit in range(ln, hn+1):
            for first in range(1, 11-bit):
                num = first
                for tail in range(first+ 1, first+ bit):
                    num = num* 10 + tail

                if low <= num <= high:
                    arr.append(num)
                elif num> high:
                    break
        
        return sorted(arr)