```
class Solution:
    def convert(self, s: str, numRows: int) -> str:
        j,flag,list1=0,True,[]
        if numRows==1 or len(s)<=numRows: return s  #处理numRows为1，或者字符串长度小于numRows数
        for i in range(numRows): list1.append('')   #初始化一个list列表
        for val in s:                               #字符串输出
            list1[j]=list1[j]+val                   #在指定的list项后添加新增字符串
            if flag:                                #指针循环方向
                j+=1                                #0-numRows-1
                if j ==numRows-1: flag=False        #到达最大值后改变标志为标示
            elif flag==False:                       #反转处理
                j-=1
                if j==0:flag=True 
        return "".join(list1)
```





