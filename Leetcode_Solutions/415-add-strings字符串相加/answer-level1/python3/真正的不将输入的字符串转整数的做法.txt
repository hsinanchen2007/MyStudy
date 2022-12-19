根据题意，不能将字符串直接转为整数，不能将字符串转整数那就不转喽，我把整数和结果转字符串就好了，不过时间就有点慢喽。
`class Solution:
    def addStrings(self, num1: str, num2: str) -> str:
        d = {}#存放字符串加法当前位结果值
        z = {}#存放进位判断值
        n1 = len(num1)
        n2 = len(num2)
        if n1>n2:
            n1 = n2
        if n1==0:
            return num1+num2
        if n1 == 1:
            if num1 == "0":
                return num2
            elif num2 == "0":
                return num1
        for i in range(0,10):
            for j in range(10):
                #用双循环生成所有单位字符串相加结果，这里将空间字典存值减少一半；
                d[str(i)+str(j)]=str((i+j)%10)
                d[str(i)+str(j)+"1"]=str((i+j+1)%10)
                z[str(i)+str(j)]=(i+j)//10
                z[str(i)+str(j)+"1"]=(i+j+1)//10
        c = 0#进位标志
        n1 = len(num1)
        n2 = len(num2)
        k = ""
        if n1>n2:#取短判断，这下面可以进行代码简化
            for i in range(1,n2+1):
                if c:
                    k=d[num1[-i]+num2[-i]+"1"]+k
                    c = z[num1[-i]+num2[-i]+"1"]
                else:
                    k=d[num1[-i]+num2[-i]]+k
                    c = z[num1[-i]+num2[-i]]
            i = n2+1
            while c:#短字符串用完还有进位处理
                if i<=n1:
                    k=d[num1[-i]+"0"+"1"]+k
                    c = z[num1[-i]+"0"+"1"]
                    i += 1
                else:
                    k = "1"+k
                    return k
            k=num1[0:n1-i+1]+k
        elif n1 == n2:
            for i in range(1,n2+1):
                if c:
                    k=d[num1[-i]+num2[-i]+"1"]+k
                    c = z[num1[-i]+num2[-i]+"1"]
                else:
                    k=d[num1[-i]+num2[-i]]+k
                    c = z[num1[-i]+num2[-i]]
            if c:
                k = "1"+k
        else:
            for i in range(1,n1+1):
                if c:
                    k=d[num1[-i]+num2[-i]+"1"]+k
                    c = z[num1[-i]+num2[-i]+"1"]
                else:
                    k=d[num1[-i]+num2[-i]]+k
                    c = z[num1[-i]+num2[-i]]
            i = n1+1
            while c:
                if i<=n2:
                    k=d[num2[-i]+"0"+"1"]+k
                    c = z[num2[-i]+"0"+"1"]
                    i+=1
                else:
                    k = "1"+k
                    return k
            k=num2[0:n2-i+1]+k
        return k
`