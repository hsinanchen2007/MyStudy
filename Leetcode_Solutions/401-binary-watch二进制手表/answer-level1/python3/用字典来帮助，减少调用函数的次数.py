一开始，想到了，暴力方法，看了一个同学的暴力写法，很好。
我想了一下，用字典来改进

getone 函数，就是得到一个非负整数到底，变成2进制，里面有多少个1 ，

创建分钟字典，把 0到 59 分钟，分类，根据 这个整数到底含有几个 bit 1 ，2进制

同样创建hour  小时的字典 。小时不能出现12:08 ，应该为0:08 ，不要12

我写的一般，如果看不懂，请写几个打印语句，在自己的电脑上执行一下吧





`class Solution(object):
    def readBinaryWatch(self, num):
        """
        :type num: int
        :rtype: List[str]
        """
        
        def getone(nn):
            #how many bit 1 in the num nn inside
            cc=0
            while nn!=0 :
                cc+=1
                nn=nn&(nn-1)
            return cc  
        
        
        minutes={}
        minutes[0]=[]
        minutes[1]=[]
        minutes[2]=[]
        minutes[3]=[]
        minutes[4]=[]
        minutes[5]=[]
        minutes[6]=[]
        
        hour={}
        hour[0]=[]
        hour[1]=[]
        hour[2]=[]
        hour[3]=[]
        hour[4]=[]
        
        for i in range(0,60):
            #only call getone 60 times
            temp=getone(i)
            minutes[temp].append(i)
            if i<12:
                hour[temp].append(i)
  
        lista=[]
        for a in hour.keys():
            for b in  minutes.keys():
                if a+b ==num:           #the point  
                    lista.append((a,b))
        
        res=[]
        for hh,mm in lista: 
            for hh1 in hour[hh]: # the correct hour list
                for mm1 in minutes[mm]: #the correct minutes list 
                    
                    ss=str(hh1)+":"+str(mm1).zfill(2)
                    
                    res.append(ss)
        return res `