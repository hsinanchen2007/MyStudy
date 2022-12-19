通过三层循环，第一层循环i表示正整数的大小。
第二层循环开始进行当前计数计算
第三层循环判断是否和前一个数相同，相同则计数+1.
```
class Solution:
    def countAndSay(self, n: int) -> str:
        st = "1"
        #第一层循环表示正整数大小，有些类似于数列
        i=1
        while i < n:
            temp = st 
            st = ""
            j = 0
            #第二层循环，根据temp计算st
            while j <= len(temp)-1:
                
                count = 0
                #计算count 
                while count ==0 or (j<=len(temp)-1 and temp[j]==temp[j-1]):
                    j += 1
                    count +=1 

                st = st + str(count)+str(temp[j-1])
                #j+=1
            i+=1
                
        return st
```
