class Solution:
    def convert(self, s: str, numRows: int) -> str:
        
        length=len(s)
        if numRows==1: #如果只有一行，原顺序输出
            return s
        res=''
        n=2*numRows-2 #这个值经常用到，就先算出来了
        i=0
        while True: 
            index=i*(n)  #第一行索引
            if index>length-1: #判断这一行是否结束
                break
            res+=s[index]          
            i+=1
        
        for i in range(1,numRows-1):  #处理中间行
            j=0
            while True:       
                index1=i+(j*n)       #索引1（竖列）
                if index1>length-1:
                    break
                res+=s[index1]
                index2=index1+n-2*i    #在第一个索引的基础上算第二个索引（在斜列上），与行数有关           
                if index2>length-1:
                    break
                res+=s[index2]
                j+=1

        i=0
        while True:
            index=numRows-1+(i*n) #最后一行索引
            if index>length-1:
                break
            res+=s[index]
            i+=1
            
        
        return res
        