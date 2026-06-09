class Solution:
    def reverse(self, x: int) -> int:
        a=str(abs(x))  #对x取绝对值，并转换为字符串
        n=len(a)      
        sum=0
        for i in range(n):  #反转
            index=n-1-i
            if index==(n-1) and a[index]=="0":
                pass
            else:
                sum=int(a[index])+sum*10
                
        lim_num=2**31   #输出结果
        if (x<0 and -sum<-lim_num) or(x>0 and sum>lim_num-1)or x==0:
            return 0
        else:
            if x<0:
                return -sum
            else:
                return sum