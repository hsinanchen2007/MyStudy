class Solution:
    def convert(self, s: str, numRows: int) -> str:
        
        lst=[[] for i in range(numRows)]
        new_lst=[]
        if not s:
            return s
        
        if numRows == 1:
            return s
        

        else:
            n = 2 * numRows - 2
            for i,letter in enumerate(s):
                try:
                    lst[i%n].append(letter)
                except:
                    lst[n-i%n].append(letter)
            
        for i in range(numRows):
            new_lst=new_lst+lst[i]
        new_str=''.join(new_lst)    
        return new_str


O(n)
O(n)