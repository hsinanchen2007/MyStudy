python 28ms ； python3 62ms
#我的想法：int ——> str 倒序 删除0 溢出 特殊情况
#我的主要是按字符类型来做的，我把我学的基础都放上去了。
#后面我看了其它大佬的思路，还可以用求余，殊途同归，思路差不多，方法不同。
```
class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        if x == 0: #排出for里面将0去掉后，如果是0而返回空的结果
            return 0
        else:
            xr = list(reversed(str(x))) #将其以str倒序
            lens = len(str(x)) #获得长度
            for  i in range(lens):
                if str(x)[i] != '0': #倒序后，如果前面有0，则删除，一直到遇到首个不为0的数时，跳出for
                    break
                else:
                    del xr[i] #del删除会将xr里的元素删除，在if中str(x)[i]如果是xr，则会导致遇到删除后的遍历，会跳过下一位，而进入删除后的下一位。
            if x<0:
                xr.pop() #会删除最后一位
                xr.insert(0,'-') #在第一位加个负号；另外也可以用xr-xr*2，也能得到负数
            xr = int(''.join(xr)) #转回整型
            #考虑溢出问题
            if xr in range(-2**31,2**31-1): #pow(-2,31) pow(2,31);python3
            #if -2**31 <= xr <= 2**31-1:   #python
                return xr
            else:
                return 0
```
