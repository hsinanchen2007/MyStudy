class Solution:
    def binaryGap(self, N: int) -> int:
        def Find1(str1:str,num1:int,num2:int):
            index=[]
            for i in range(num1,num2):
                if str1[i]=='1':
                    index.append(i)
            return index
        str1=bin(N)
        print(str1)
        str1=[str1[i] for i in range(2,len(str1))]
        sum0=0
        index=Find1(str1,0,len(str1))
        for i in range(len(index)-1):
            sum0=sum0 if sum0>(index[i+1]-index[i]) else (index[i+1]-index[i]) 

        
        return sum0